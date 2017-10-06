/*!
 * \file var.h
 * \summary define global, hardware's statuses variable
 *
 * \author
 *
 * \date October 2017
 *
 *
 */
#ifndef _VAR_H_
#define _VAR_H_
#define INA219_measure_battery_addr 0x40
#define INA219_measure_pv_addr 0x41

#include <Adafruit_SSD1306.h> 
#include <INA219.hpp>	
#include <IOPins.h>	
#include <RTCTimer.h>

/* an I2C-inherited class that provides a constructed default */
class I2CPreInit : public I2C
{
public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl)
    {
        frequency(400000);
        start();
    };
};
I2CPreInit g_I2C_object(I2C_SDA, I2C_SCL);

Adafruit_SSD1306_I2c g_lcd_object(g_I2C_object, NC);  /* LCD object*/



INA219 g_battery_measure_object(I2C_SDA, I2C_SCL, INA219_measure_battery_addr); /*INA current sensors object for battery*/
INA219 g_pv_measure_object(I2C_SDA, I2C_SCL, INA219_measure_pv_addr);		/*INA current sensors object for solar panel*/
#endif /*_VAR_H_*/
