#include "control/cppadpino.h"

#include "yaml-cpp/yaml.h"

YAML::Node config = YAML::LoadFile("/home/xie/Desktop/learn/carpole/cartplole/src/manage/config/config.yaml");
mpc::mpc()
{

pinocchio::urdf::buildModel("/home/xie/Desktop/learn/carpole/cartplole/src/models/inverted_pendulum/cartpole.urdf",model);

data = pinocchio::Data(model);
admodel = model.cast<ADScalar>();
addata = ADData(admodel);
    std::cout<<admodel.name<<std::endl;
    std::cout<<"admodel.nq"<<admodel.nq<<std::endl;
    std::cout<<"admodel.nv"<<admodel.nv<<std::endl;
    std::cout << "number of joints = " << admodel.njoints;
    std::cout << "number of frames = " << admodel.nframes;
    std::cout << "number of bodies = " << admodel.nbodies;
    std::cout << "lower joint configuration limit = "
              << admodel.lowerPositionLimit;
    std::cout << "upper joint configuration limit = "
              << admodel.upperPositionLimit;
    std::cout << "maximal joint velocities = " << admodel.velocityLimit;
    std::cout << "maximal joint torques = " << admodel.effortLimit;

    std::cout << "joint name & joint position:" << std::endl;


    for (size_t i = 0; i < admodel.njoints; i++) {
      std::cout << admodel.names.at(i) << std::endl;
      std::cout << addata.oMi.at(i).translation().transpose() << std::endl;
    }
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_q;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_v;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_tau;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> x_input;
      std::vector<double>  ad_ddq(6);
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_ddq_out;

    std::vector<double> x_input_vec(6);
    ad_q.resize(admodel.nq);
    ad_v.resize(admodel.nv);
    ad_tau.resize(admodel.nv);
    ad_ddq.resize(admodel.nv);
    x_input.resize(admodel.nq+admodel.nv+admodel.nv);
    ad_ddq_out.resize(2);

    ad_q(0,0)= config["p1"].as<double>();
    ad_q(1,0)= config["p2"].as<double>();

    ad_v(0,0)= config["p3"].as<double>();
    ad_v(1,0)= config["p4"].as<double>();

    ad_tau(0,0)= config["p5"].as<double>();
    ad_tau(1,0)= config["p6"].as<double>();




    x_input.block(0,0,admodel.nq,1) = ad_q ;
    x_input.block(admodel.nq,0,admodel.nv,1) =ad_v ;
    x_input.block(admodel.nq+admodel.nv,0,admodel.nv,1) =ad_tau  ;

    pinocchio::aba(admodel,addata,ad_q,ad_v,ad_tau);



    std::cout<<addata.ddq<<std::endl;
    for(int i=0;i<admodel.nq+admodel.nv+admodel.nv;i++)
    {
     x_input_vec.at(i)=  CppAD::Value(x_input(i,0)) ;
    }
    kin_dyn = setdyn();
   
    ad_ddq=kin_dyn.Forward(0,x_input_vec);

for(int i=0;i<2;i++)
   std::cout<<ad_ddq.at(i) <<std::endl;;
}

CppAD::ADFun<double> mpc::setdyn()
{
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_q;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_v;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_tau;
    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> ad_ddq;

    Eigen::Matrix<ADScalar,Eigen::Dynamic, 1> x_input;

    x_input.resize(admodel.nq+admodel.nv+admodel.nv);
    ad_q.resize(admodel.nq);
    ad_v.resize(admodel.nv);
    ad_tau.resize(admodel.nv);
    ad_ddq.resize(admodel.nv);
    
    ad_q(0,0)= config["p1"].as<double>();
    ad_q(1,0)= config["p2"].as<double>();

    ad_v(0,0)= config["p3"].as<double>();
    ad_v(1,0)= config["p4"].as<double>();

    ad_tau(0,0)= config["p5"].as<double>();
    ad_tau(1,0)= config["p6"].as<double>();

CppAD::Independent(x_input);

    
  ad_q =    x_input.block(0,0,2,1) ;
  ad_v =    x_input.block(2,0,2,1) ;
  ad_tau =  x_input.block(4,0,2,1) ;

    
    pinocchio::aba(admodel,addata,ad_q,ad_v,ad_tau);
// ad_ddq =ad_q+ ad_v+ad_tau;
    for(int i=0;i<admodel.nv;i++)
    {
    ad_ddq(i,0) =  addata.ddq(i);
    }

return   CppAD::ADFun<double>(x_input,ad_ddq);



}

void mpc::solve()
{

}


