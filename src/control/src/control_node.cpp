#include "control/control_node.h"
#include <rclcpp/logging.hpp>
#include "control/cppadpino.h"


void ControlNode::update_data() {
  RCLCPP_INFO_ONCE(this->get_logger(), "updating ControlNode data");

  Eigen::Vector4d current_states;
  current_states(0) = state_msg.x;
  current_states(1) = state_msg.q;
  current_states(2) = state_msg.dx;
  current_states(3) = state_msg.dq;

  torque_msg.u = mpc.solve(current_states);
  std::cout<<" torque_msg.u"<< torque_msg.u<<std::endl;
torque_publisher_->publish(torque_msg);
return ;

}