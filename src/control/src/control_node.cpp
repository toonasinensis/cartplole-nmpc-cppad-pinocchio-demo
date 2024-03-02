#include "control/control_node.h"
#include "control/doubleintger.h"
#include <rclcpp/logging.hpp>


using namespace casadi;
Nmpc nmpc;
void ControlNode::update_data() {
  RCLCPP_INFO_ONCE(this->get_logger(), "updating ControlNode data");
  
// X_next = nmpc.kinematic_equation_(input)
Eigen::Vector2d current_states;
Eigen::Vector2d desired_states;

torque_publisher_->publish(torque_msg);
return ;

}