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
    
}

/* Creates joint type parts */
void InitializationManager::createJoints(){
    
    /* int id, std::string name, float mass, float length) */
    this->partcontainer_m.joints.add("J1", RoboticArm::Joint("Joint 1", 1, 1));
    this->partcontainer_m.joints.add("J2", RoboticArm::Joint("Joint 1", 1, 1));
    this->partcontainer_m.joints.add("J3", RoboticArm::Joint("Joint 1", 1, 1));
    this->partcontainer_m.joints.add("J4", RoboticArm::Joint("Joint 1", 1, 1));
    this->partcontainer_m.joints.add("J5", RoboticArm::Joint("Joint 1", 1, 1));

}