/******************************************************************************
 * @file    EnergyStorage.cpp
 * @author   Dua Nguyen
 * @brief
 * @date     Dec. 2017
 * @date modified 2017/12/5
 * @version 1.0.0
 * Copyright(C) 2017
 * All rights reserved.
 *
 *****************************************************************************/
#include "EnergyStorage.h"
/** constructor
 *
 *  @param mosi - mosi pin connect to sd card socket
 *  @param miso - miso pin connect to sd card socket
 *  @param sclk - sclk pin connect to sd card socket
 *  @param cs - cs pin connect to sd card socket
 */
EnergyStorage::EnergyStorage (PinName mosi, PinName miso, PinName sclk, PinName cs) {
    sd = new SDBlockDevice (mosi, miso, sclk, cs);
    fs = new FATFileSystem (SD_MOUNT_PATH);
    fs->mount(sd);
    energy_value = 0;
    power_value = 0;
    fd = NULL;
    err_flag = false;
}
/** @brief: initialization object.
 */
void EnergyStorage::Init() {
    cal_tick.attach(callback(this, &EnergyStorage::EnergyCal), ENERGY_CALC_PERIOD);
    save_tick.attach(callback(this, &EnergyStorage::EnergySave), ENERGY_STORAGE_PERIOD);
}
/** @brief: Getter Energy value to display on lcd
 *  @return: energy_value.
 */
float32_t EnergyStorage::GetEnergy() {
    return energy_value;
}
/** @brief: method for power on self test
 *  @return: if pass the test, return true, else return false.
 */
bool EnergyStorage::PowerOnSelfTest() {
    bool return_value;
    fd = fopen(FULL_LOG_FILE_PATH, "a");
    if(NULL == fd) {
        return_value = false;
    } else {
        return_value = true;
    }
    fclose(fd);
    return return_value;
}
/** @brief: updating power measurements in real time for energy measurements.
 *  @param: value - the power value measure by ina219
 */
void EnergyStorage::UpdatePower(float32_t value) {
    power_value = value;
}
/** @brief: verify/read the latest stored value.
 *  @return: true - read successfully, else return false.
 */
bool EnergyStorage::ReloadEnergy() {
    fd = fopen(FULL_LOG_FILE_PATH, "r");
    if(NULL == fd) {
        fclose(fd);
        return false;
    } else {
          fseek(fd, 0, SEEK_END);
          uint32_t length = ftell(fd);
          if(length > 25) {
          fseek(fd, length - 25, SEEK_SET);
      } else {
          fseek(fd, 0, SEEK_SET);
      }
        while (!feof(fd)) {
            fscanf(fd, "%f", &energy_value);
        }
        fclose(fd);
        return true;
    }
}
/** @brief: function calculate energy.
 */
void EnergyStorage::EnergyCal() {
    energy_value += power_value * ENERGY_CALC_PERIOD / 3600;
}
/** @brief: function save energy into sd card.
 */
void EnergyStorage::EnergySave() {
    fd = fopen(FULL_LOG_FILE_PATH, "a");
    if(NULL == fd) {
        err_flag = true;
        fclose(fd);
    } else {
        err_flag = false;
        fprintf(fd, "\r\n%f", energy_value);
        fclose(fd);
    }
}
