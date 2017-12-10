/******************************************************************************
 * @file    EnergyStorage.h
 * @author   Dua Nguyen
 * @brief
 * @date     Dec. 2017
 * @date modified 2017/12/5
 * @version 1.0.0
 * Copyright(C) 2017
 * All rights reserved.
 *
 *****************************************************************************/
#ifndef LIB_ENERGYSTORAGE_ENERGYSTORAGE_H_
#define LIB_ENERGYSTORAGE_ENERGYSTORAGE_H_
#include <mbed.h>
#include "FATFileSystem.h"
#include "SDBlockDevice.h"
#define ENERGY_STORAGE_PERIOD 1
#define ENERGY_CALC_PERIOD 0.5
#define SD_MOUNT_PATH         "sd"
#define FULL_LOG_FILE_PATH    "/sd/energylog.txt"
/** Class: EnergyStorage
 * @brief: calculate energy and storage in sd card
 * Example:
 * @code
 * @TODO: update
 * @endcode
 */
class EnergyStorage {
 protected:
    float32_t energy_value; /*energy in Wh*/
    float32_t power_value;  /*power in W*/
    bool err_flag;
    Ticker cal_tick;
    Ticker save_tick;
    SDBlockDevice *sd;  // mosi, miso, sclk, cs
    FATFileSystem *fs;
    FILE* fd;
    /** @brief: function calculate energy.
     */
    void EnergyCal();
    /** @brief: function save energy into sd card.
     */
    void EnergySave();

 public:
   /** constructor
    *
    *  @param mosi - mosi pin connect to sd card socket
    *  @param miso - miso pin connect to sd card socket
    *  @param sclk - sclk pin connect to sd card socket
    *  @param cs - cs pin connect to sd card socket
    */
    EnergyStorage(PinName mosi, PinName miso, PinName sclk, PinName cs);
    /** @brief: initialization object.
     */
    void Init();
    /** @brief: Getter Energy value to display on lcd
     *  @return: energy_value.
     */
    float32_t GetEnergy();
    /** @brief: method for power on self test
     *  @return: if pass the test, return true, else return false.
     */
    bool PowerOnSelfTest();
    /** @brief: updating power measurements in real time for energy measurements.
     *  @param: value - the power value measure by ina219
     */
    void UpdatePower(float32_t value);
    /** @brief: verify/read the latest stored value.
     *  @return: true - read successfully, else return false.
     */
    bool ReloadEnergy();
};
#endif  // LIB_ENERGYSTORAGE_ENERGYSTORAGE_H_
