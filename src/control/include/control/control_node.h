#pragma once
#include <chrono>
#include "control/doubleintger.h"

#include <functional>
#include "mujoco/mujoco.h"

#include <interface/msg/detail/state__struct.hpp>
#include <interface/msg/detail/torque__struct.hpp>
#include <rclcpp/rclcpp.hpp>

#include "interface/msg/state.hpp"
#include "interface/msg/torque.hpp"

using namespace std::chrono_literals;

using namespace std::chrono_literals;
class ControlNode : public rclcpp::Node {
 public:
  ControlNode() : Node("ctrl", "") {


       torque_publisher_ = this->create_publisher<interface::msg::Torque>("torque", 1);
        
       state_subscribtion_ = this->create_subscription<interface::msg::State>("state",1,
       std::bind(&ControlNode::update_callback, this, std::placeholders::_1));


           update_timer_ = this->create_wall_timer(
        2ms, std::bind(&ControlNode::update_data, this));
 
  }


  rclcpp::TimerBase::SharedPtr update_timer_;
  rclcpp::TimerBase::SharedPtr state_timer_;


  interface::msg::State state_msg;
  interface::msg::Torque torque_msg;

  rclcpp::Publisher<interface::msg::Torque>::SharedPtr torque_publisher_  ;
  rclcpp::Subscription<interface::msg::State>::SharedPtr state_subscribtion_;


 private:
  mjData* d_ = nullptr;



  bool flag_data_init_ = false;
   void update_data();
   void update_callback(const interface::msg::State& _state_msg)
   {
    state_msg = _state_msg;
   }
};
