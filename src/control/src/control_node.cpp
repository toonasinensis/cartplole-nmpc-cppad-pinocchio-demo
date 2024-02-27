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
desired_states(1) = 5;
std::cout<<"state_msg"<<state_msg.dx<<std::endl;
current_states(0) =state_msg.dx ;
current_states(1) =state_msg.x ;
// current_states(3) = 1;


nmpc.solve(current_states,desired_states);
// std::cout<<"sdffff";
   auto res = nmpc.getFirstU();
std::cout<<res[0];
torque_msg.u = res[0];
  flag_data_init_ = true;
torque_publisher_->publish(torque_msg);
return ;

}