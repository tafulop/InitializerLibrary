/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   InitializerTest.cpp
 * Author: fulop
 *
 * Created on Mar 27, 2016, 1:08:42 PM
 */

#include "InitializerTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(InitializerTest);

InitializerTest::InitializerTest() {
}

InitializerTest::~InitializerTest() {
}

void InitializerTest::setUp() {
}

void InitializerTest::tearDown() {
}


void InitializerTest::initialize() {
    
    InitializationManager& initm = InitializationManager::getInstance();
    
    initm.createRoboticArmModel();

    CPPUNIT_ASSERT(true);
}


void InitializerTest::jointCount(){

    PartContainerManager& pc_man = PartContainerManager::getInstance();

    CPPUNIT_ASSERT(pc_man.joints.getItemNumber() == 5);

}

