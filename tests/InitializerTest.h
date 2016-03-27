/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   InitializerTest.h
 * Author: fulop
 *
 * Created on Mar 27, 2016, 1:08:42 PM
 */

#ifndef INITIALIZERTEST_H
#define INITIALIZERTEST_H

#include "../InitializationManager.h"

#include <cppunit/extensions/HelperMacros.h>



class InitializerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(InitializerTest);

    /* TEST FUNCTIONS */
    CPPUNIT_TEST(initialize);
    CPPUNIT_TEST(jointCount);

    CPPUNIT_TEST_SUITE_END();

public:
    InitializerTest();
    virtual ~InitializerTest();
    void setUp();
    void tearDown();

private:
    
    /* TEST FUNCTIONS */
    void initialize();
    
    void jointCount();
    
    
};

#endif /* INITIALIZERTEST_H */

