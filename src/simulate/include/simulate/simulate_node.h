#pragma once
#include <chrono>

#include <functional>
#include "mujoco/mujoco.h"

#include <interface/msg/detail/state__struct.hpp>
#include <interface/msg/detail/torque__struct.hpp>
#include <rclcpp/rclcpp.hpp>

#include "interface/msg/state.hpp"
#include "interface/msg/torque.hpp"

using namespace std::chrono_literals;
class SimulateNode : public rclcpp::Node {
 public:
  SimulateNode() : Node("sim", "inv") {
       state_publisher_ = this->create_publisher<interface::msg::State>("state", 1);
       torque_subscribtion_ = this->create_subscription<interface::msg::Torque>("torque",1,
       std::bind(&SimulateNode::update_callback, this, std::placeholders::_1));


           update_timer_ = this->create_wall_timer(
        2ms, std::bind(&SimulateNode::update_data, this));
 
  }

   
  void set_mutex(std::recursive_mutex* mutex) {
    mutex_ = mutex;
    return;
  }

  void set_model(mjData* d) {
    d_ = d;
    return;
  }

  void set_ctrl_ptr(double* global_ctrl_ptr) {
    global_ctrl_ptr_ = global_ctrl_ptr;
    return;
  }

  bool is_ready() { return d_ && mutex_; }
  std::mutex set_torque_mutex;

  bool is_use_cheat_mode;

  rclcpp::TimerBase::SharedPtr update_timer_;
  rclcpp::TimerBase::SharedPtr state_timer_;


  interface::msg::State state_msg;
  interface::msg::Torque torque_msg;

  rclcpp::Publisher<interface::msg::State>::SharedPtr state_publisher_;
  rclcpp::Subscription<interface::msg::Torque>::SharedPtr torque_subscribtion_;


 private:
  mjData* d_ = nullptr;
  double* global_ctrl_ptr_ = nullptr;
  std::recursive_mutex* mutex_ = nullptr;
  std::atomic_bool flag_toque_update;


  bool flag_data_init_ = false;
   void update_data();
   void update_callback(const interface::msg::Torque& _torque_msg);
};
