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
EnergyStorage::EnergyStorage (PinName mosi, PinName miso, PinName sclk, PinName cs):
sd(mosi, miso, sclk, cs), fs(SD_MOUNT_PATH, &sd) {
    energy_value = 0;
    fd = NULL;
}
float32_t EnergyStorage::GetEnergy() {
    return energy_value;
}
