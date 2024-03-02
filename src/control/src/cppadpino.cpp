#include "control/cppadpino.h"

YAML::Node config = YAML::LoadFile("/home/xie/Desktop/learn/carpole/cartplole/src/manage/config/config.yaml");

dyn::dyn()
{

pinocchio::urdf::buildModel("/home/xie/Desktop/learn/carpole/cartplole/src/models/inverted_pendulum/cartpole.urdf",model);

data = pinocchio::Data(model);
admodel = model.cast<ADScalar>();
addata = ADData(admodel);
    std::cout<<admodel.name<<std::endl;
    std::cout<<"admodel.nq"<<admodel.nq<<std::endl;
    std::cout<<"admodel.nv"<<admodel.nv<<std::endl;
    std::cout << "number of joints = " << admodel.njoints;
    std::cout << "number of frames = " << admodel.nframes;
    std::cout << "number of bodies = " << admodel.nbodies;
    std::cout << "lower joint configuration limit = "
              << admodel.lowerPositionLimit;
    std::cout << "upper joint configuration limit = "
              << admodel.upperPositionLimit;
    std::cout << "maximal joint velocities = " << admodel.velocityLimit;
    std::cout << "maximal joint torques = " << admodel.effortLimit;

    std::cout << "joint name & joint position:" << std::endl;


    for (size_t i = 0; i < admodel.njoints; i++) {
      std::cout << admodel.names.at(i) << std::endl;
      std::cout << addata.oMi.at(i).translation().transpose() << std::endl;
    }
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_q;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_v;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_tau;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> x_input;
      std::vector<double>  ad_ddq(6);
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_ddq_out;

    std::vector<double> x_input_vec(6);
    ad_q.resize(admodel.nq);
    ad_v.resize(admodel.nv);
    ad_tau.resize(admodel.nv);
    ad_ddq.resize(admodel.nv);
    x_input.resize(admodel.nq+admodel.nv+admodel.nv);
    ad_ddq_out.resize(2);

    ad_q(0,0)= config["p1"].as<double>();
    ad_q(1,0)= config["p2"].as<double>();

    ad_v(0,0)= config["v1"].as<double>();
    ad_v(1,0)= config["v2"].as<double>();

    ad_tau(0,0)= config["t1"].as<double>();
    ad_tau(1,0)= config["t2"].as<double>();




    x_input.block(0,0,admodel.nq,1) = ad_q ;
    x_input.block(admodel.nq,0,admodel.nv,1) =ad_v ;
    x_input.block(admodel.nq+admodel.nv,0,admodel.nv,1) =ad_tau  ;

    pinocchio::aba(admodel,addata,ad_q,ad_v,ad_tau);



    std::cout<<addata.ddq<<std::endl;
    for(int i=0;i<admodel.nq+admodel.nv+admodel.nv;i++)
    {
     x_input_vec.at(i)=  CppAD::Value(x_input(i,0)) ;
    }
    kin_dyn = setdyn();
   
    ad_ddq=kin_dyn.Forward(0,x_input_vec);

for(int i=0;i<2;i++)
   std::cout<<ad_ddq.at(i) <<std::endl;;
}

CppAD::ADFun<double> dyn::setdyn()
{
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_q;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_v;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_tau;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_ddq;

    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> x_input;

    x_input.resize(admodel.nq+admodel.nv+admodel.nv);
    ad_q.resize(admodel.nq);
    ad_v.resize(admodel.nv);
    ad_tau.resize(admodel.nv);
    ad_ddq.resize(admodel.nv);
    
    // ad_q(0,0)= config["p1"].as<double>();
    // ad_q(1,0)= config["p2"].as<double>();

    // ad_v(0,0)= config["p3"].as<double>();
    // ad_v(1,0)= config["p4"].as<double>();

    // ad_tau(0,0)= config["p5"].as<double>();
    // ad_tau(1,0)= config["p6"].as<double>();

CppAD::Independent(x_input);

    
  ad_q =    x_input.block(0,0,2,1) ;
  ad_v =    x_input.block(2,0,2,1) ;
  ad_tau =  x_input.block(4,0,2,1) ;

    
    pinocchio::aba(admodel,addata,ad_q,ad_v,ad_tau);
// ad_ddq =ad_q+ ad_v+ad_tau;
    for(int i=0;i<admodel.nv;i++)
    {
    ad_ddq(i,0) =  addata.ddq(i);
    }

return   CppAD::ADFun<double>(x_input,ad_ddq);
}

std::vector<ADScalar> dyn::RHS(std::vector<ADScalar> x_input,
                               ADScalar u) {

  
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_q;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_v;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_tau;
   
    // std::cout << "x_input.size()" << x_input.size() << "u.size()"<<std::endl;
    ad_q.resize(admodel.nq);
    ad_v.resize(admodel.nv);
    ad_tau.resize(admodel.nv);
  
    ad_q(0,0)= x_input.at((0));
    ad_q(1,0)= x_input.at((1));

    ad_v(0,0)= x_input.at((2));
    ad_v(1,0)= x_input.at((3));

    ad_tau(0,0)= u;
    ad_tau(1,0)= 0;
      // std::cout << "pass"<<std::endl;

    pinocchio::aba(admodel,addata,ad_q,ad_v,ad_tau);

    std::vector<ADScalar> dstate(4);
    for (int i = 0; i < admodel.nv; i++) {
      dstate.at(i) = ad_v(i,0);
    dstate.at(i + admodel.nv) =  addata.ddq(i);
    }

  return  dstate;
}



MPC::~MPC() {}
MPC::MPC(){};
std::pair<std::vector<double>, Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>>
 MPC::solve(const Eigen::VectorXd state)
    {
    typedef CPPAD_TESTVECTOR(double) Dvector;

    const double x = state[0];
    const double q = state[1];
    const double dx = state[2];
    const double dq = state[3];


    // Number of independent variables (includes both states and inputs):
    // For example, if the state is a 4 element vector, the actuators is a 2 element vector
    // and there are 10 timesteps. The number of variables is: 4 * 10 + 2 * 9

    // N timesteps = N - 1 actuations:
    size_t n_vars = N * CP_STATE_NUM + (N - 1) * CP_CTRL_NUM;

    //TODO: 
    // Number of constraints:
    size_t n_constraints = N * (CP_STATE_NUM + CP_CTRL_NUM);

    // Initial value of the independent variables.
    Dvector vars(n_vars);

    // Should be 0 except for the initial values:
    for (size_t i = 0; i < n_vars; ++i) {
        vars[i] = 0.0;
    }

    // Set the initial variable values:
    vars[START_X] = x;
    vars[START_Q] = q;
    vars[START_DX] = dx;
    vars[START_DQ] = dq;

    // Lower and upper limits for x:
    Dvector vars_lowerbound(n_vars);
    Dvector vars_upperbound(n_vars);

    // Set all non-actuators upper and lowerlimits
    // to the max negative and positive values:
    for (size_t i = 0; i < START_U; ++i) {
        vars_lowerbound[i] = -1.0e19;
        vars_upperbound[i] = 1.0e19;
    }



    // The upper and lower limits of actuators are set to -25 and 25
    // NOTE: Feel free to change this to something else.
    for (size_t i = START_U; i < n_vars; ++i) {
        vars_lowerbound[i] = -25;
        vars_upperbound[i] = 25;
    }


    // Lower and upper limits for constraints:
    Dvector constraints_lowerbound(n_constraints);
    Dvector constraints_upperbound(n_constraints);

    // Should be 0 except for the initial values:
    for (size_t i = 0; i < n_constraints; ++i) {
        constraints_lowerbound[i] = 0;
        constraints_upperbound[i] = 0;
    }

    // Set the initial variable values:

    constraints_lowerbound[START_X] = x;
    constraints_lowerbound[START_Q] = q;
    constraints_lowerbound[START_DX] = dx;
    constraints_lowerbound[START_DQ] = dq;


    constraints_upperbound[START_X] = x;
    constraints_upperbound[START_Q] = q;
    constraints_upperbound[START_DX] = dx;
    constraints_upperbound[START_DQ] = dq;



    // Object that computes objective and constraints:
    FG_eval fg_eval;

    // Options:
    // NOTE: You don't have to worry about these options.

    std::string options;

    // Uncomment this if you'd like more print information
    options += "Integer print_level  0\n";

    // NOTE: Setting sparse to true allows the solver to take advantage
    // of sparse routines, this makes the computation MUCH FASTER. If you
    // can uncomment 1 of these and see if it makes a difference or not but
    // if you uncomment both the computation time should go up in orders of
    // magnitude.
    options += "Sparse  true        forward\n";
    options += "Sparse  true        reverse\n";

    // NOTE: Currently the solver has a maximum time limit of 0.5 seconds.
    // Change this as you see fit.
    // options += "Numeric max_cpu_time          1.5\n";

    // Solve the problem:

    CppAD::ipopt::solve_result<Dvector> solution;

    CppAD::ipopt::solve<Dvector, FG_eval>(
        options,
        vars,
        vars_lowerbound,
        vars_upperbound,
        constraints_lowerbound,
        constraints_upperbound,
        fg_eval,
        solution
    );

    // Check some of the solution values:

    const bool ok = solution.status == CppAD::ipopt::solve_result<Dvector>::success;
    const auto cost = solution.obj_value;

    if (!ok) {
       std:: cout <<  std::endl << "There was an error calculating the solution." <<std:: endl <<std:: endl;
    }

    double total_u = 0;
    // double total_throttle = 0;

    // for (size_t i = 0; i < AVG_N_; ++i) {
    //     total_u += solution.x[START_U + i];
    //     // total_throttle += solution.x[START_A + i];
    // }

    // {...} is shorthand for creating a vector:

    std::vector<double> resultvec = {
      cost,
      solution.x[START_U]

    };
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> resultmat;
    resultmat.resize(CP_CTRL_NUM+CP_STATE_NUM ,N-1);
    for (size_t i = 0; i < N - 1; ++i) {
      resultmat(0, START_X + i) = solution.x[START_X + i];
      resultmat(1, START_X + i) = solution.x[START_Q + i];
      resultmat(2, START_X + i) = solution.x[START_DX + i];
      resultmat(3, START_X + i) = solution.x[START_DQ + i];
      resultmat(4, START_X + i) = solution.x[START_U + i];
    }

    return std::pair<std::vector<double>, Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>>(resultvec,resultmat) ;
}
