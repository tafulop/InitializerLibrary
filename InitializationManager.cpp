/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InitializationManager.cpp
 * Author: fulop
 * 
 * Created on March 26, 2016, 9:44 PM
 */

#include "InitializationManager.h"

InitializationManager::InitializationManager() {
}

InitializationManager::~InitializationManager() {
}

/* singleton */
InitializationManager& InitializationManager::getInstance(){
    static InitializationManager instance;
    return instance;
}

/* creates all type of parts for the robotic arm */
void InitializationManager::createRoboticArmModel(){
    
    // create joints
    this->createJoints();
    
    // init calculation
    this->initializeCalculations();
    
}

/* Creates joint type parts */
void InitializationManager::createJoints(){
    
    std::cout << "Creating and storing Joints in PartContainer..." << std::endl;
    
    /* int id, std::string name, float mass, float length) */
    this->partcontainer_m.joints.add("J1", RoboticArm::Joint("Joint 1", 0.00001, 0.00001, -170, +170));
    this->partcontainer_m.joints.add("J2", RoboticArm::Joint("Joint 2", 0.00001, 0.00001, -75, +75));
    this->partcontainer_m.joints.add("J3", RoboticArm::Joint("Joint 3", 1, 0.00001, -60, +60));
    this->partcontainer_m.joints.add("J4", RoboticArm::Joint("Joint 4", 1, 0.00001, -170, 170));
    this->partcontainer_m.joints.add("J5", RoboticArm::Joint("Joint 5", 1, 0.00001, -60, +60));

    std::cout << "PartContainer successfully populated with Joints. Number of joints: " << partcontainer_m.joints.getItemNumber() << std::endl;
    
}


void InitializationManager::initializeCalculations(){
    
    
    std::cout << "Initializing calculations..." << std::endl;
    
    // create DHT matrices
    std::vector<DenavitHartenbergMatrix*> matrices;
    
    // alfa, a, theta, d
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(90,    216,      0,   0));  // 0
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(0,     469,     0,  0));   // 1
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(90,    0,      0,   0));   // 2
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(-90,   0,      0,   0));  // 3
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(90,    0,      0,   0));   // 4
    matrices.emplace(matrices.end(), new DenavitHartenbergMatrix(0,     0,      0,  0));  // 5
    
    std::cout << "Step 1/5 - Matrices created." << std::endl;
    
    // set offsets for D
    matrices.at(0)->setOffset(DenavitHartenbergMatrix::OFFSET_VARIABLE::D, 221);
    matrices.at(3)->setOffset(DenavitHartenbergMatrix::OFFSET_VARIABLE::D, 440+78);
    matrices.at(5)->setOffset(DenavitHartenbergMatrix::OFFSET_VARIABLE::D, 92);
    
    std::cout << "Step 2/5 - D offsets set." << std::endl;
    
    // set offsets for THETA
    matrices.at(1)->setOffset(DenavitHartenbergMatrix::OFFSET_VARIABLE::THETA, 90);
    matrices.at(5)->setOffset(DenavitHartenbergMatrix::OFFSET_VARIABLE::THETA, 90);
    
    std::cout << "Step 3/5 - THETA offsets set." << std::endl;
    
    // attach joints to the matrices
    matrices.at(0)->assignToJoint(partcontainer_m.joints.get("J1"));
    matrices.at(1)->assignToJoint(partcontainer_m.joints.get("J2"));
    matrices.at(2)->assignToJoint(partcontainer_m.joints.get("J3"));
    matrices.at(3)->assignToJoint(partcontainer_m.joints.get("J4"));
    matrices.at(4)->assignToJoint(partcontainer_m.joints.get("J5"));
    
    std::cout << "Step 4/5 - Joints has been assigned to DHTs." << std::endl;
    
    
    // store joints
    for(DenavitHartenbergMatrix* m : matrices){
        this->forwardKinematics.storeDHTMatrix(m);
    }
    
    std::cout << "Step 5/5 - DHTs stored." << std::endl;
    
}