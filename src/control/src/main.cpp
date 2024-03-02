#include "control/control_node.h"
#include "backward.hpp"
#include "control/cppadpino.h"

// #include "control/nmpc.h"
std::shared_ptr<ControlNode> ctrl_node_ptr;




#define BACKWARD_HAS_DW 1
namespace backward{
    backward::SignalHandling sh;
    }



    int main(int argc, char **argv) {
      // dyn dyn_maic_test;
      // dyn_maic_test.test_dynamics();

  // // print version, check compatibility
  rclcpp::init(argc, argv);
  ctrl_node_ptr = std::make_shared<ControlNode>();

    rclcpp::spin(ctrl_node_ptr);
    rclcpp::shutdown();

  
}