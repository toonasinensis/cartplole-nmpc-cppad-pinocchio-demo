#pragma once
#include "yaml-cpp/yaml.h"

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
# include <cppad/ipopt/solve.hpp>


#include <iostream>

#define  USE_COUT 0

#define CP_STATE_NUM 4
#define CP_CTRL_NUM 1

  typedef double Scalar;
  typedef CppAD::AD<Scalar> ADScalar;
  
  typedef pinocchio::ModelTpl<Scalar> Model;
  typedef Model::Data Data;

  typedef pinocchio::ModelTpl<ADScalar> ADModel;
  typedef ADModel::Data ADData;

class dyn{
public:
dyn();
~dyn() = default;
CppAD::ADFun<double> setdyn();

// void solve();
pinocchio::ModelTpl< Scalar> model;
pinocchio::DataTpl< Scalar> data;

pinocchio::ModelTpl< ADScalar> admodel;
pinocchio::DataTpl< ADScalar> addata;

CppAD::ADFun<double> kin_dyn;

std::vector<ADScalar> RHS(std::vector<ADScalar> x_input,ADScalar u);
public:
//dyn paramters:



};

// We want T to be 1 seconds, so we could use DT = 0.1 seconds and N = 10;
const double DT = 0.02; // DT >= LAG
const size_t N = 10;

// The solver takes all the state variables and actuator variables in a
// single vector. Thus, we should establish where one variable starts and
// another ends to make our lifes easier:
const size_t START_X = 0;
const size_t START_Q = START_X + N;
const size_t START_DX = START_Q + N;
const size_t START_DQ = START_DX + N;
//actuator HORINZON is N-1
const size_t START_U = START_DQ + N;
// const size_t START_U1 = START_U + N-1;


class FG_eval {

public:

dyn cartpole_dyn;




std::vector<double> weight = {10, 10, 10, 10, 1};

FG_eval() {
YAML::Node config = YAML::LoadFile("/home/xie/Desktop/learn/carpole/cartplole/src/manage/config/config.yaml");

weight.at((0)) = config["w0"].as<double>();
weight.at((1)) = config["w1"].as<double>();
weight.at((2)) = config["w2"].as<double>();
weight.at((3)) = config["w3"].as<double>();
weight.at((4)) = config["w4"].as<double>();

#if  USE_COUT
std::cout << "used" << std::endl;
#endif

};
    typedef CPPAD_TESTVECTOR(CppAD::AD<double>) ADvector;

    void operator()(ADvector &fg, const ADvector &vars) {
        // std::cout<<"enter"<<std::endl;

        // `fg` is a vector containing the cost and constraints.
        // `vars` is a vector containing the variable values (state & actuators).

        CppAD::AD<double> cost = 0;

        // COSTS:
        // Define the cost related to the reference state and anything you think may be beneficial:

        // Reference State Cost:

        for (size_t t = 0; t < N; ++t) {
            cost += weight.at((0)) * CppAD::pow(vars[START_X + t], 2);
            cost += weight.at((1)) * CppAD::pow(vars[START_Q + t], 2);
            
            cost += weight.at((2)) * CppAD::pow(vars[START_DX + t], 2);
            cost += weight.at((3))  * CppAD::pow(vars[START_DQ + t], 2);
        }

        // Control Cost (minimize the use of actuators):

        for (size_t t = 0; t < N - 1; ++t) {
            cost += weight.at((4)) * CppAD::pow(vars[START_U + t], 2);
        }

      // std::cout<<"vars passsed"<<std::endl;

        // The cost is stored is the first element of fg, fg[0]:
        fg[0] = cost;

        // CONSTRAINTS:
        // In this section you'll setup the model constraints.

        // Initial constraints:
        // We add 1 to each of the starting indices due to cost being located at index 0 of fg:
        fg[1 + START_X] = vars[START_X];
        fg[1 + START_Q] = vars[START_Q];
        fg[1 + START_DX] = vars[START_DX];
        fg[1 + START_DQ] = vars[START_DQ];
        fg[1 + START_U] = vars[START_U];
        // fg[1 + START_EPSI] = vars[START_EPSI];

        // std::cout<<"init fg pass"<<std::endl;
        // The rest of the constraints:
        for (size_t t = 1; t < N; ++t) {
            // State at t + 1:
            CppAD::AD<double> x1 = vars[START_X + t];
            CppAD::AD<double> q1 = vars[START_Q + t];
            CppAD::AD<double> dx1 = vars[START_DX + t];
            CppAD::AD<double> dq1 = vars[START_DQ + t];

            // CppAD::AD<double> u1 = vars[START_U + t];
            // CppAD::AD<double> epsi1 = vars[START_EPSI + t];

            // State at t:
            CppAD::AD<double> x0 = vars[START_X + t-1];
            CppAD::AD<double> q0 = vars[START_Q + t-1];
            CppAD::AD<double> dx0 = vars[START_DX + t-1];
            CppAD::AD<double> dq0 = vars[START_DQ + t-1];


            // Actuators at t:
            CppAD::AD<double> u0 = vars[START_U + t-1];

            //  std::cout<<"all init passed"<<std::endl;
            
            // The idea here is to constraint this value to be 0.
            // NOTE: The use of `AD<double>` and use of `CppAD`!
            // This is also CppAD can compute derivatives and pass these to the solver.

            // For a polynomial of 2nd degree:
            // AD<double> f0 = coeffs_[0] + coeffs_[1] * x0;
            // AD<double> psides0 = CppAD::atan(coeffs_[1]);

            // For a polynomial of nth degree:

            std::vector<ADScalar> x_input;
            x_input.push_back(x0);
             x_input.push_back(q0);
             x_input.push_back(dx0);
             x_input.push_back(dq0);
             std::vector<ADScalar> u;
            //  u.push_back(u0);
               std::vector<ADScalar> dx_output;
      dx_output =  cartpole_dyn.RHS(x_input,u0);

            fg[1 + START_X + t] = x1 - dx_output.at((0)) * DT + x0;
            fg[1 + START_Q + t] = q1 - dx_output.at((1)) * DT + q0;
            fg[1 + START_DX + t] = dx1 - dx_output.at((2)) * DT + dx0;
            fg[1 + START_DQ + t] = dq1 - dx_output.at((3)) * DT + dq0;
            // fg[1 + START_CTE + t] = cte1 - (f0 - y0 + v0 * CppAD::sin(epsi0) * DT);

            // A sign has ben changed in this list one ( + v0/LF_) to work properly
            // on the emulator:
            // fg[1 + START_EPSI + t] = epsi1 - (psi0 - psides0 - v0/LF_ * delta0 * DT);
        }
    }
};


class MPC {
private:
public:

  MPC();
  double u_max;
   // Object that computes objective and constraints:
    FG_eval fg_eval;

  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the average of the first N actuations.
  // std::pair<std::vector<double>, Eigen::Matriclear
  //  x<double,Eigen::Dynamic,Eigen::Dynamic>>
double solve(
      const Eigen::VectorXd state  );

};