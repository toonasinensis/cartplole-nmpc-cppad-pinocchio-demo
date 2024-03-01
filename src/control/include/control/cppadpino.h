#pragma once
// #include <Eigen/eigen>
#include "pinocchio/autodiff/cppad.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/multibody/data.hpp"

#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/crba.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include "pinocchio/algorithm/rnea-derivatives.hpp"
#include "pinocchio/algorithm/aba.hpp"
#include "pinocchio/algorithm/aba-derivatives.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"

#include "pinocchio/parsers/sample-models.hpp"


#include <iostream>

  typedef double Scalar;
  typedef CppAD::AD<Scalar> ADScalar;
  
  typedef pinocchio::ModelTpl<Scalar> Model;
  typedef Model::Data Data;

  typedef pinocchio::ModelTpl<ADScalar> ADModel;
  typedef ADModel::Data ADData;

class mpc{
public:
mpc();
~mpc() = default;
CppAD::ADFun<double> setdyn();

void solve();
pinocchio::ModelTpl< Scalar> model;
pinocchio::DataTpl< Scalar> data;

pinocchio::ModelTpl< ADScalar> admodel;
pinocchio::DataTpl< ADScalar> addata;

CppAD::ADFun<double> kin_dyn;


private :
int N =10;

Eigen::Matrix<ADScalar,4, Eigen::Dynamic> X;
Eigen::Matrix<ADScalar,4, Eigen::Dynamic> U;
// Eigen::Matrix<ADScalar,4, Eigen::Dynamic> X1;
// Eigen::Matrix<ADScalar,4, Eigen::Dynamic> U1;





};