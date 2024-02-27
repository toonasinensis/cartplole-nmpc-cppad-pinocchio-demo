#include "control/control_node.h"
// #include "control/nmpc.h"
std::shared_ptr<ControlNode> ctrl_node_ptr;



int main(int argc, char** argv) {



  // print version, check compatibility
  rclcpp::init(argc, argv);
  ctrl_node_ptr = std::make_shared<ControlNode>();

    rclcpp::spin(ctrl_node_ptr);
    rclcpp::shutdown();


}