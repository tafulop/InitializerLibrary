/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InitializationManager.h
 * Author: fulop
 *
 * Created on March 26, 2016, 9:44 PM
 */

#ifndef INITIALIZATIONMANAGER_H
#define INITIALIZATIONMANAGER_H

#include "../PartContainerLibrary/PartContainerManager.h"
#include "../PartContainerLibrary/PartContainer.h"
#include "../CalculatorLibrary/ForwardKinematics.h"

class InitializationManager {
    
public:
    
    /**
     * Singleton
     * @return 
     */
    static InitializationManager& getInstance();
    
    
    /**
     * Creates the necessary parts for the robotic arm.
     */
    void createRoboticArmModel();

    
    /**
     * Destructor.
     */
    virtual ~InitializationManager();
     
private:

    // Part container
    PartContainerManager& partcontainer_m = PartContainerManager::getInstance();
    
    // Forward kinematics
    ForwardKinematics& forwardKinematics = ForwardKinematics::getInstance();

    /**
     * Creates all joint type parts.
     */
    void createJoints();
    
    
    /**
     * Stores the created Joints in calculator object, creates the DHT matrices.
     */
    void initializeCalculations();
    
        
    /**
     * Default constructor.
     */
    InitializationManager();
};

#endif /* INITIALIZATIONMANAGER_H */

