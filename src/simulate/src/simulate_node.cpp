#include "simulate/simulate_node.h"

#include <Eigen/Dense>
#include <chrono>
#include <interface/msg/detail/torque__struct.hpp>

/*
in global frame:
framepos
framequat
framelinvel
in local frame:
imu
 q
 ang_vel
 acc
*/

void SimulateNode::update_data() {
  RCLCPP_INFO_ONCE(this->get_logger(), "updating sim data");

  double *sensordata = nullptr;
  {
    std::lock_guard lg(*mutex_);
    sensordata = d_->sensordata;
  }
  state_msg.quat.set__x_w(sensordata[1]);
  state_msg.quat.set__y_w(sensordata[2]);
  state_msg.quat.set__z_w(sensordata[3]);
  state_msg.quat.set__w_w(sensordata[0]);

  state_msg.set__ang_x_w(sensordata[4]) ;
  state_msg.set__ang_y_w(sensordata[5]);
  state_msg.set__ang_z_w(sensordata[6]) ;

//     state_msg.set__x(sensordata[0]);
//     state_msg.set__q(sensordata[1]);
//     state_msg.set__dx(sensordata[2]);
//     state_msg.set__dq(sensordata[3]);

//   flag_data_init_ = true;
state_publisher_->publish(state_msg);
// return ;

}
void SimulateNode::update_callback(const interface::msg::Torque& _torque_msg)
{
torque_msg = _torque_msg;
}