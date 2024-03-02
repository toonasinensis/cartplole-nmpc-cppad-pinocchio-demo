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

  {
  YAML::Node config = YAML::LoadFile("/home/xie/Desktop/learn/carpole/"
                                     "cartplole/src/manage/config/config.yaml");

    x_test(0)= config["p1"].as<double>();
     x_test(1)= config["p2"].as<double>();

     x_test(2)= config["v1"].as<double>();
     x_test(3) = config["v2"].as<double>();
  }



    MPC mpc;


    mpc.solve(x_test);


  
}