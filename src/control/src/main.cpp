#include "control/control_node.h"
#include "control/cppadpino.h"
#include "backward.hpp"

// #include "control/nmpc.h"
std::shared_ptr<ControlNode> ctrl_node_ptr;




#define BACKWARD_HAS_DW 1
namespace backward{
    backward::SignalHandling sh;
}
int main(int argc, char** argv) {
  Eigen::VectorXd x_test(4);
        // std::vector<ADScalar> u;

  {
  YAML::Node config = YAML::LoadFile("/home/xie/Desktop/learn/carpole/"
                                     "cartplole/src/manage/config/config.yaml");

    x_test(0)= config["p1"].as<double>();
     x_test(1)= config["p2"].as<double>();

     x_test(2)= config["v1"].as<double>();
     x_test(3) = config["v2"].as<double>();
            //  u.push_back(config["t1"].as<double>());
  }


dyn cartpole_dyn;

        
    // std::vector<ADScalar> x_input;
    // x_input.push_back(x_test(0));
    // x_input.push_back(x_test(1));
    // x_input.push_back(x_test(2));
    // x_input.push_back(x_test(3));

    // std::vector<ADScalar> dx_output;
    // std::cout << "x_input.size()" << x_input.size() << "u.size()"<<std::endl;
    // ADScalar u=10;
             
    // dx_output =  cartpole_dyn.RHS(x_input,u);

FG_eval fg_eval;
    typedef CPPAD_TESTVECTOR(CppAD::AD<double>) ADvector;

          ADvector fg(1+ N * CP_STATE_NUM + (N - 1) * CP_CTRL_NUM);
           ADvector vars( N * CP_STATE_NUM + (N - 1) * CP_CTRL_NUM);
          fg_eval(fg,vars);
      
    // ad_tau(0,0)= config["p5"].as<double>();
    // ad_tau(1,0)= config["p6"].as<double>();

    MPC mpc;

      Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> resultmat;
      resultmat.resize(CP_CTRL_NUM + CP_STATE_NUM, N - 1);
    std::vector<double> resultvec;

    auto result = mpc.solve(x_test);
  //   resultvec = result.first;
  //   resultmat = result.second;
  //   std::cout<<"cost"<<resultvec.at(0)<< "current ctrl:" <<
  //   resultvec.at(1)<<std::endl;
  //
  //
  //
  // 

  
}