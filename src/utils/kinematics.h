/* related header files */
#pragma once
#include <pinocchio/fwd.hpp>  // always include it before any other header

#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include "pinocchio/parsers/sample-models.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/spatial/explog.hpp"

class leg_dynamic {
 private:
  /* data */
 public:
  leg_dynamic(const std::string &urdf_filename);
  ~leg_dynamic();
  void forward_kin_frame(Eigen::Vector3d q, Eigen::Vector3d dq,
                         Eigen::Vector3d ddq, Eigen::Vector3d &x,
                         Eigen::Vector3d &dx, Eigen::Vector3d &ddx,
                         pinocchio::FrameIndex id);

  void inverse_kin_frame(Eigen::Vector3d &q, Eigen::Vector3d &dq,
                         Eigen::Vector3d &ddq, Eigen::Vector3d x,
                         Eigen::Vector3d dx, Eigen::Vector3d ddx,
                         pinocchio::FrameIndex id,
                         Eigen::Vector3d q_init = Eigen::Vector3d(-0.5, 0.5,
                                                                  0.2));

  pinocchio::Model model;
  pinocchio::Data data;

  Eigen::Vector3d inverse_dynamic_frame(Eigen::Vector3d q, Eigen::Vector3d dq,
                                        Eigen::Vector3d ddq);
  Eigen::Matrix3d get_jacobian(Eigen::Vector3d q, pinocchio::FrameIndex id);
  //   Eigen::Vector3d get_position(Eigen::Vector3d q, pinocchio::FrameIndex
  //   id); Eigen::Vector3d get_velocity(Eigen::Vector3d q, Eigen::Vector3d qd,
  //                                pinocchio::FrameIndex id);
  void get_shoulder_pos();

  void send_cmd() {}
  void recv_state() {}
};

inline leg_dynamic::leg_dynamic(const std::string &urdf_filename) {
  pinocchio::urdf::buildModel(urdf_filename, model);
  pinocchio::Data temp_data(model);

  data = temp_data;
}

inline leg_dynamic::~leg_dynamic() {}

// void send_cmd() {}
// void recv_state() {}
