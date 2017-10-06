/*!
 * \file main.cpp
 * \date 2017/10/06 
 *
 * \author 
 * Contact: 
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/


#include <mbed.h>
#include <var.h>      /*Store global variable for interacting with hardware*/
#include <LCDController.h> 
#include <INAReader.h>
#include <RTCTimer.h>
#include <KeyboardController.h>

/*initialization lcd object*/
LCDController lcdcontroller(&g_lcd_object);

/*initialization current, voltage measuring object*/
INAReader ina_reader(&g_battery_measure_object, &g_pv_measure_object);

/*initialization keyboard object*/
KeyboardController keyboard(SELECT_BUTTON_PIN, SET_BUTTON_PIN, INVERTER_ON_PIN);

/*initialization realtime clock object*/
RTC_Timer rtc_timer;

int main() {
    /*Display logo watershed on screen*/
    lcdcontroller.showLogo();

	/*Wait for 3 seconds*/
    wait(3);

    while(true) 
    {
        /*Read values from INA modules*/
        ina_reader.Scan();

        /*Update realtime clock*/
        rtc_timer.Update();

        /*Update properties of lcd object*/
        lcdcontroller.setBattVolt(ina_reader.getBattVolt());
        lcdcontroller.setBattCurr(ina_reader.getBattCurr());
        lcdcontroller.setBattPower(ina_reader.getBattPower());
        lcdcontroller.setPVVolt(ina_reader.getPVVolt());
        lcdcontroller.setPVCurr(ina_reader.getPVCurr());
        lcdcontroller.setPVPower(ina_reader.getPVPower());
        lcdcontroller.setTime(rtc_timer.GetHour(), rtc_timer.GetMinute(), rtc_timer.GetSecond());

        /*Update LCD screen with menu index*/
        lcdcontroller.updateScreen(keyboard.menu_index);
    }
}
