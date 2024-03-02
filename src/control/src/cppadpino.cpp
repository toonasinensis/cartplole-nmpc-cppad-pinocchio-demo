#include "control/cppadpino.h"
#include <fstream>


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

void dyn::test_dynamics() {
  std::cout<<"test dyn"<<std::endl;
  double time_all = 30;
  double time_interval = 0.001;

  std::vector<ADScalar> X0_test(4);
  std::vector<ADScalar> X_test(4);


  X0_test.at((0)) = 0;
  X0_test.at((1)) = 0.1;
  X0_test.at((2)) = 0;
  X0_test.at((3)) = 0;
  std::ofstream dataFile;
  	dataFile.open("test.csv", std::ios::out | std::ios::trunc);

  double timer = 0;
  dataFile << "x"<< ","<< "q"<< ","<< "dx" <<","<< "dq"<<","<< "t"<< std::endl;
  std::vector<ADScalar> dX0_test(4);

  for (int i = 0; i < time_all / time_interval; i++) {
    timer+=0.001;
    // dX0_test = RHS(X0_test, 0);
    // for (int j = 0; j < 4; j++) {
    //       X_test.at((j)) = X0_test.at((j)) + dX0_test.at((j))*time_interval;
    // }
    X_test = cartpole_dynamics_discrete(X0_test,0,time_interval);
    X0_test = X_test;
  dataFile <<X0_test.at((0))<< ","<< X0_test.at((1))<< ","<< X0_test.at((2)) <<","<<X0_test.at((3))<<","<<timer<< std::endl;
  }
  	dataFile.close();                            // 关闭文档
  std::cout<<"test end"<<std::endl;

}

std::vector<ADScalar>
dyn::cartpole_dynamics_discrete(const std::vector<CppAD::AD<double>> &x ,CppAD::AD<double> u,CppAD::AD<double> dt) {
  int nx = 4,nu=1;
std::vector<CppAD::AD<double>> k1(nx), k2(nx), k3(nx), k4(nx);
  std::vector<CppAD::AD<double>> x_next(nx);

  std::vector<CppAD::AD<double>> x_temp(nx + nu);
  for (int i = 0; i < nu; ++i) {
    x_temp[nx + i] = x[nx + i];
  }
  // 计算k1
  k1 = RHS(x,u);
  // 计算k2
  for (int i = 0; i < nx; ++i) {
    x_temp[i] = x[i] + 0.5 * k1[i] * dt;
  }
  k2 = RHS(x_temp,u);
  // 计算k3
  for (int i = 0; i < nx; ++i) {
    x_temp[i] = x[i] + 0.5 * k2[i] * dt;
  }
  k3 = RHS(x_temp,u);
  // 计算k4
  for (int i = 0; i < nx; ++i) {
    x_temp[i] = x[i] + k3[i] * dt;
  }
  k4 = RHS(x_temp,u);

  // 更新状态
  for (int i = 0; i < nx; ++i) {
    x_next[i] =
        x[i] + (1.0 / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]) * dt;
  }

  return x_next;
  
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



//      std::vector<CppAD::AD<double>> dx(4); // 状态变量的变化率
//   // x_cart的动力学方程
//   dx[0] =  x_input[2];
//   // theta的动力学方程
//   dx[1] = x_input[3];

//  CppAD:: AD<double> s1, c1;
//   s1 = sin(x_input[1]);
//   c1 = cos(x_input[1]);
//   double m_pole = 0.2;
//   double m_cart = 2;
//   double l = 1.0/2;
//   double g= 9.8;
//   // x_cart_dot的动力学方程
//   dx[2] =
//       (u+ m_pole * l * s1 * x_input[3] * x_input[3] - 3 * m_pole * g * s1 * c1 / 4) /
//       (m_cart + m_pole - 3 * m_pole * c1 * c1 / 4);
//   // theta_dot的动力学方程
//   dx[3] = 3 * (g * s1 - dx[2] * c1) / 4 / l;

//   return dx;

    return dstate;



    
}

// // continuous dynamics
// vector<AD<double>>
// Cartpole_Dynamics::cartpole_dynamics_continuous(const vector<AD<double>> &x) {
 
// }

MPC::~MPC() {}
MPC::MPC(){};
//std::pair<std::vector<double>, Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>>
 double MPC::solve(const Eigen::VectorXd state)
    {
    typedef CPPAD_TESTVECTOR(double) Dvector;

    const double x  = state[0];
    const double q  = state[1];
    const double dx = state[2];
    const double dq = state[3];

    u_max = config["umax"].as<double>();
    // Number of independent variables (includes both states and inputs):
    // For example, if the state is a 4 element vector, the actuators is a 2 element vector
    // and there are 10 timesteps. The number of variables is: 4 * 10 + 2 * 9

    // N timesteps = N - 1 actuations:
    size_t n_vars = N * CP_STATE_NUM + (N - 1) * CP_CTRL_NUM;

    //TODO: 
    // Number of constraints:
    size_t n_constraints = N * (CP_STATE_NUM );

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
        vars_lowerbound[i] = -u_max;
        vars_upperbound[i] = u_max;
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
#if  USE_COUT

    std::cout << "vars" << vars.size() << "vars_lowerbound"
              << vars_lowerbound.size() << "vars_upperbound"
              << vars_upperbound.size() << "constraints_lowerbound"
              << constraints_lowerbound.size() << "constraints_upperbound"
              << constraints_upperbound.size() << std::endl;
    #endif
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
    #if  USE_COUT
 std::cout<<"cost : "<<resultvec.at((0))<<std::endl;
 std::cout<<"u : "<<resultvec.at((1))<<std::endl;
 std::cout<<"resultmat.row((0)) x"<<resultmat.row((0))<<std::endl;
 std::cout<<"resultmat.row((1)) q"<<resultmat.row((1))<<std::endl;
 std::cout<<"resultmat.row((2)) dx"<<resultmat.row((2))<<std::endl;
 std::cout<<"resultmat.row((3)) dq"<<resultmat.row((3))<<std::endl;
std::cout<<"resultmat.row((4)) u"<<resultmat.row((4))<<std::endl;

#endif
return  resultvec.at((1));
    // return std::pair<std::vector<double>, Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>>(resultvec,resultmat) ;
}
