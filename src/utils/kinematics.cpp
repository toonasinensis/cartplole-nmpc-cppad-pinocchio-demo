#include "kinematics.h"
void leg_dynamic::forward_kin_frame(Eigen::Vector3d q, Eigen::Vector3d dq,
                                    Eigen::Vector3d ddq, Eigen::Vector3d &x,
                                    Eigen::Vector3d &dx, Eigen::Vector3d &ddx,
                                    pinocchio::FrameIndex id) {
  pinocchio::forwardKinematics(model, data, q, dq, ddq);
  pinocchio::updateFramePlacements(model, data);
  // pinocchio::framesForwardKinematics(model, data, q);
  x = data.oMf[id].translation();
  dx = pinocchio::getFrameVelocity(model, data, id,
                                   pinocchio::LOCAL_WORLD_ALIGNED)
           .linear();

  ddx = pinocchio::getFrameAcceleration(model, data, id,
                                        pinocchio::LOCAL_WORLD_ALIGNED)
            .linear();

  // std::cout<<'\n'<<"x: "<<x.transpose()<< '\n'<<"dx "<< \
    // dx.transpose()<<'\n'<<"ddx"<<ddx.transpose()<<std::endl;
}

void leg_dynamic::get_shoulder_pos() {
  pinocchio::FrameIndex shoulder_id = model.getFrameId("FL_calf_joint");
  pinocchio::forwardKinematics(model, data, Eigen::Vector3d(0, 0, 0));
  pinocchio::updateFramePlacements(model, data);
  std::cout << shoulder_id << std::endl;
  std::cout << data.oMf[shoulder_id].translation() << std::endl;
}

void leg_dynamic::inverse_kin_frame(Eigen::Vector3d &q, Eigen::Vector3d &dq,
                                    Eigen::Vector3d &ddq, Eigen::Vector3d x,
                                    Eigen::Vector3d dx, Eigen::Vector3d ddx,
                                    pinocchio::FrameIndex id,
                                    Eigen::Vector3d q_init) {
  Eigen::Vector3d temp_q = q_init;
  const double eps = 1e-3;
  const int IT_MAX = 1000;
  const double DT = 1e-1;
  const double damp = 1e-6;

  pinocchio::SE3 oMdes(Eigen::Matrix3d::Identity(), x);
  bool success = false;

  Eigen::Vector3d err;
  pinocchio::Data::Matrix6x J(6, model.nv);
  pinocchio::Data::Matrix6x dJ(6, model.nv);
  // Eigen::Matrix<double,6,6> dJ;
  J.setZero();
  dJ.setZero();
  int i = 0;
  for (i = 0; i < IT_MAX; i++) {
    pinocchio::forwardKinematics(model, data, temp_q);
    pinocchio::computeJointJacobians(
        model, data,
        temp_q);  // if we use this ,we can get frame or joint jocobians

    pinocchio::updateFramePlacements(model, data);
    pinocchio::getFrameJacobian(model, data, id, pinocchio::LOCAL_WORLD_ALIGNED,
                                J);  // cal this, you need forwardKinematics

    pinocchio::SE3 T_temp = data.oMf[id];
    err = oMdes.translation() -
          T_temp.translation();  // must compute the forward kinematics

    if (err.norm() < eps) {
      success = true;
      break;
    }
    if (i >= IT_MAX) {
      success = false;
      break;
    }

    Eigen::Vector3d dq = 20 * J.block(0, 0, 3, 3).transpose() * err;
    temp_q = pinocchio::integrate(model, temp_q, dq * DT);

    //  if(!(i%10))
    //  std::cout << i << ": error = " << err.transpose() << std::endl;
  }

  if (success) {
    std::cout << "Convergence achieved!" << std::endl;
  } else {
    std::cout << "\nWarning: the iterative algorithm has not reached "
                 "convergence to the desired precision"
              << std::endl;
  }
  q = temp_q;

  dq = J.block(0, 0, 3, 3).inverse() * dx;
  pinocchio::computeJointJacobiansTimeVariation(
      model, data, q, dq);  // if we use this .we can get frame or joint
                            // derviation of jocabians
  pinocchio::getFrameJacobianTimeVariation(
      model, data, id, pinocchio::LOCAL_WORLD_ALIGNED,
      dJ);  // this can repace getframejacobian

  ddq = J.block(0, 0, 3, 3).inverse() * (ddx - (dJ * dq).block(0, 0, 3, 3));
  // std::cout<<"dj"<<dJ<<std::endl;
  std::cout << "\nresult: " << q.transpose() << dq.transpose() << "ddq"
            << ddq.transpose() << std::endl;
  std::cout << "    i =   " << i << std::endl;
  std::cout << "\nfinal error: " << err.transpose() << std::endl;
}

Eigen::Vector3d leg_dynamic::inverse_dynamic_frame(Eigen::Vector3d q,
                                                   Eigen::Vector3d dq,
                                                   Eigen::Vector3d ddq) {
  pinocchio::rnea(model, data, q, dq, ddq);
  return data.tau;
}

Eigen::Matrix3d leg_dynamic::get_jacobian(Eigen::Vector3d q,
                                          pinocchio::FrameIndex id) {
  pinocchio::Data::Matrix6x J(6, model.nv);
  // pinocchio::Data::Matrix6x dJ(6,model.nv);
  // Eigen::Matrix<double,6,6> dJ;
  J.setZero();
  pinocchio::forwardKinematics(model, data, q);

  pinocchio::computeJointJacobians(
      model, data, q);  // if we use this ,we can get frame or joint jocobians
  pinocchio::updateFramePlacements(model, data);

  pinocchio::getFrameJacobian(model, data, id, pinocchio::LOCAL_WORLD_ALIGNED,
                              J);  // cal this, you need forwardKinematics

  return J.block(0, 0, 3, 3);
}

// Eigen::Vector3d leg_dynamic::get_position(Eigen::Vector3d q,
//                                           pinocchio::FrameIndex id) {
//   pinocchio::Data::Vector3 position;
//   position.setZero();
//   pinocchio::forwardKinematics(model, data, q);
//   pinocchio::updateFramePlacements(model, data);

//   pinocchio::SE3 oMdes(Eigen::Matrix3d::Identity(), Eigen::Vector3d::Zero());
//   position = data.oMi[id].actInv(oMdes);

//   return position;
// }

// Eigen::Vector3d leg_dynamic::get_velocity(Eigen::Vector3d q, Eigen::Vector3d
// qd,
//                                           pinocchio::FrameIndex id) {
//   pinocchio::Data::Vector3 velocity;
//   velocity.setZero();
//   pinocchio::forwardKinematics(model, data, q, qd);
//   pinocchio::updateFramePlacements(model, data);

//   pinocchio::SE3 oMdes(Eigen::Matrix3d::Identity(), Eigen::Vector3d::Zero());
//   velocity = pinocchio::getVelocity(model, data, id, LOCAL_WORLD_ALIGNED)
//                  .actInv(oMdes);

//   return velocity;
// }
