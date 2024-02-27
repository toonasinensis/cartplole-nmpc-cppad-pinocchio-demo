#include "control/doubleintger.h"
#include <codecvt>
#include <functional>


Nmpc::Nmpc() {
    
    
    N_ = 20;
    dt_ = 0.1;
    u_max_ = 40;
    w_max_ = 2;
    vector<double> weights = {10,1000,0.001}; //Q,R
    u_min_ = - u_max_;
    w_min_ = - w_max_;
    
    Q_ = DM::zeros(STATE_NUM,STATE_NUM); //索引之前初始化size
    R_ = DM::zeros(1,1);

    setWeights(weights);
    kinematic_equation_ = setKinematicEquation();
    // std::cout<<kinematic_equation_<<std::endl;
}
Nmpc::~Nmpc() {}

void Nmpc::setWeights(vector<double> weights) {
Q_(0,0) = weights.at(0);
Q_(1,1) = weights.at(1);
R_(0,0) = weights.at(2);



}


Function Nmpc:: setKinematicEquation(){
   auto dx = MX::sym("dx");
    auto x = MX::sym("x");

    auto u = MX::sym("u");
    // auto ddx = MX::sym("ddx");
    

    auto rhs =MX:: vertcat({u/M,dx});
    auto state = MX:: vertcat({dx,x});
    return Function("kinematic_equation",{state,u} , {rhs});

    }
  
bool Nmpc::solve(Eigen::Vector2d current_states, Eigen::Vector2d desired_states) {
    
    // cout << " solveWDR" << endl;
    Opti opti = Opti();
    //这样？
    Slice all;

    MX cost = 0;
    X = opti.variable(STATE_NUM, N_ + 1);
    U = opti.variable(1, N_);//ariable need to programn


    MX X_ref = opti.parameter(STATE_NUM, N_ + 1);
    MX X_cur = opti.parameter(STATE_NUM);
    DM x_tmp1 = {current_states[0], current_states[1]};
    
    DM X_end = DM::zeros(STATE_NUM,N_+1);
    for(int i=0;i<N_;i++)
    {
        X_end(all,i) = {desired_states[0], desired_states[1]};
    }
//    std::cout<< opti.debug()<<std::endl;

    opti.set_value(X_cur, x_tmp1);  //set current state
    opti.set_value(X_ref, X_end);  //set current state

    // cout << "set current state success" << endl;

     

    // X_ref = DM::zeros(STATE_NUM,N_+1);
    // reshape(X_ref_d, 4, N_ + 1);
    
    // std::cout<<"X_ref"<<X_ref<<std::endl;

    //set costfunction
    for (int i = 0; i < N_; ++i) {
        MX X_err = X(all, i) - X_ref(all, i); 
        MX U_0 = U(all, i);
        //cout << "U_0 size:" << U_0.size() << endl;
        //cout << "cost size:" << cost_.size() << endl;
        cost += MX::mtimes({X_err.T(), Q_, X_err});
        //cout << "cost size:" << cost_.size() << endl; 
       cost += MX::mtimes({U_0.T(), R_, U_0});
        //cout << "cost size:" << cost_.size() << endl;
    }

    //cout << "cost size:" << cost_.size() << endl;
    cost += MX::mtimes({(X(all, N_) - X_ref(all, N_)).T(), Q_,
                        X(all, N_) - X_ref(all, N_)});

    // cout << "cost:" << cost << endl;

    opti.minimize(cost);
    //cout << "set cost success" << endl;

    //kinematic constrains
    for (int i = 0; i < N_; ++i) {
      std::vector< MX> input(2);
        input[0] = X(all, i);
        input[1] = U(all, i);
        MX X_next = kinematic_equation_(input)[0] * dt_ + X(all, i);
        // std::cout<<kinematic_equation_(input)[0]<<std::endl;
        opti.subject_to(X_next == X(all, i + 1));
        // std::cout<<X_next<<std::endl;
    }

    //init value
    opti.subject_to(X(all, 0) == X_cur);

    //speed angle_speed limit
    

    opti.subject_to(-u_max_ <= U <= u_max_);
    // opti.subject_to(w_min_ <= w <= w_max_);

    //set solver
    casadi::Dict solver_opts;
    solver_opts["expand"] = true; //MX change to SX for speed up
    solver_opts["ipopt.max_iter"] = 10000;
    solver_opts["ipopt.print_level"] = 0;
    solver_opts["print_time"] = 0;
    solver_opts["ipopt.acceptable_tol"] = 1e-6;
    solver_opts["ipopt.acceptable_obj_change_tol"] = 1e-6;


    opti.solver("ipopt", solver_opts);


    // auto sol = opti.solve();
    // std::cout << "Cost value: " << opti.debug().value(cost) << std::endl;

    //     auto first_v =  sol.value(U)(0,0);
    // std::cout.precision(2);
    // std::cout<<"u"<<first_v<<std::endl;
    // auto predict_x = sol.value(X);
    // std::cout<<"x"<<predict_x<<std::endl;
    // // std::cout<<"X_ref"<<sol.stats()<<std::endl;
    solution_ = std::make_unique<casadi::OptiSol>(opti.solve());
//  auto first_v =  solution_->value(U)(0,0);
//     std::cout<<first_v<<std::endl;
    return true;
}
vector<double> Nmpc::getFirstU() {
    vector<double> res;
    auto first_v =  solution_->value(U)(0,0);

    res.push_back(static_cast<double>(first_v));
    // std::cout<<first_v<<std::endl;
    return res;
}

vector<double> Nmpc::getPredictX() {
    vector<double> res;
    auto predict_x = solution_->value(X);
    cout << "nomal" << endl;
    //cout << "predict_x size :" << predict_x.size() << endl;
    for (int i = 0; i <= N_; ++i) {
        res.push_back(static_cast<double>(predict_x(0, i)));
        res.push_back(static_cast<double>(predict_x(1, i)));
        //         res.push_back(static_cast<double>(predict_x(2, i)));
        // res.push_back(static_cast<double>(predict_x(3, i)));

    }
    return res;
}
