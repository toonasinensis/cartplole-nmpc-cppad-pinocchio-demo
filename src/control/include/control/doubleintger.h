#pragma once

#include "control/doubleintger.h"
#include <vector>
#include <Eigen/Dense>
#include <casadi/casadi.hpp>
#include <iostream>
#include <chrono>

#define STATE_NUM 2
#define CONTROL_NUM 1

using namespace std;
using namespace casadi;

class Nmpc
{
public:

    //mpc params
    int N_;  //horizon
    double dt_;  //step

    // //constrains
    double u_max_, u_min_;
    double w_max_, w_min_;
    
    //weights
    DM Q_, R_;

    
    MX X;
    MX U;

    double u_out;
    
    Function kinematic_equation_;
    //OptiSol solution_; 报错没有默认构造函数
    unique_ptr<casadi::OptiSol> solution_;
    

public:
    //param:
 double M = 2;
    double g = -9.8;
    Nmpc();
    ~Nmpc();

    Function setKinematicEquation();
    void setWeights(vector<double> weights);
    bool solve(Eigen::Vector2d current_states, Eigen::Vector2d desired_states);
    vector<double> getFirstU();
    vector<double> getPredictX();
};

