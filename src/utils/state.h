#pragma once
#include <Eigen/Dense>

#include "utils/param.h"
struct QuadState {
  QuadState() {
    euler_angle.setZero();
    pos.setZero();
    omega_world.setZero();
    lin_vel_world.setZero();
    lin_acc_world.setZero();
    rot_mat_world2local.setZero();
    foot_pos_local.setZero();
    foot_vel_local.setZero();
    foot_pos_world.setZero();
    foot_vel_world.setZero();
    leg_qpos.setZero();
    leg_qvel.setZero();
  }

  void reset() {
    euler_angle.setZero();
    pos.setZero();
    omega_world.setZero();
    lin_vel_world.setZero();
    lin_acc_world.setZero();
    rot_mat_world2local.setZero();
    foot_pos_local.setZero();
    foot_vel_local.setZero();
    foot_pos_world.setZero();
    foot_vel_world.setZero();
    leg_qpos.setZero();
    leg_qvel.setZero();
  }

  Eigen::Vector3d euler_angle;
  Eigen::Vector3d pos;
  Eigen::Vector3d omega_world;
  Eigen::Vector3d lin_vel_world;
  Eigen::Vector3d lin_acc_world;

  Eigen::Matrix3d rot_mat_world2local;//body相对与world，把world转换到body的旋转变换，相当于是左上角为body
  Eigen::Matrix<double, 3, NUM_LEG> foot_pos_local;
  Eigen::Matrix<double, 3, NUM_LEG> foot_vel_local;
  Eigen::Matrix<double, 3, NUM_LEG> foot_pos_world;
  Eigen::Matrix<double, 3, NUM_LEG> foot_vel_world;
  Eigen::Matrix<double, 3, NUM_LEG> leg_qpos;
  Eigen::Matrix<double, 3, NUM_LEG> leg_qvel;
};
