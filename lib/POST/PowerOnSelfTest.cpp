/******************************************************************************
 * @file    PowerOnSelfTest.h
 * @author   Dua Nguyen
 * @brief
 * @date     Nov. 2017
 * @date modified 2017/11/25
 * @version 1.0.0
 * Copyright(C) 2017
 * All rights reserved.
 *
 *****************************************************************************/
 #include "mbed.h"
 #include "PowerOnSelfTest.h"
 /************************************
  * Method:  PowerOnSelfTest::PowerOnSelfTest
  * @brief: PowerOnSelfTest constructor
  * Access: public
  * Returns:
  * Qualifier:
  * @TODO <nothing>
 ***********************************/
PowerOnSelfTest::PowerOnSelfTest () {
    POST_result = true;
    printf("Start Power On Self Test\n");
}
/*PowerOnSelfTest destructor*/
PowerOnSelfTest::~PowerOnSelfTest () {
    printf("Power On Self Test Passed!\n");
}
