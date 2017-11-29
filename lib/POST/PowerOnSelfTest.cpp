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
/** @brief: handle power on self test for ina219 (push notification)
 *  @param: value - a boolean argument pass or false the test
 *  @return: a noti string to display on lcd.
 */
const char* PowerOnSelfTest::POST_INA219(bool value) {
    if(true == value) {
        printf("INA219 POST is passed!\n");
        return "INA219: Ok!\n";
    } else {
        POST_result = false;
        printf("INA219 POST is false! Make sure that the i2c address is 0x40\n");
        return "INA219: False!\n Pls check the i2c address!";
    }
}
bool PowerOnSelfTest::GetResult() {
    return POST_result;
}
