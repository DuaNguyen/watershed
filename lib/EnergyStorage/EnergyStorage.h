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
#include "mbed.h"
#include "FATFileSystem.h"
#include "SDBlockDevice.h"
#define ENERGY_STORAGE_PERIOD 1
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
    float32_t energy_value;
    Ticker _tick;
    SDBlockDevice sd; // mosi, miso, sclk, cs
    FATFileSystem fs;
    FILE* fd;
    void EnergyCal();
public:
   /** constructor
    *
    *  @param mosi - mosi pin connect to sd card socket
    *  @param miso - miso pin connect to sd card socket
    *  @param sclk - sclk pin connect to sd card socket
    *  @param cs - cs pin connect to sd card socket
    */
    EnergyStorage (PinName mosi, PinName miso, PinName sclk, PinName cs);
    void Init();
    float32_t GetEnergy();

};
#endif /*LIB_ENERGYSTORAGE_ENERGYSTORAGE_H_*/
