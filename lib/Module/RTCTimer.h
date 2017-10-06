/*!
 * \file RTCTimer.h
 * \date 2017/10/06 
 *
 * \author 
 * Contact: 
 *
 * \brief Class for controlling real-time clock
 *
 * TODO: long description
 *
 * \note
*/


#ifndef _RTCTIMER_H_
#define _RTCTIMER_H_
#include <mbed.h>

class RTC_Timer{
public:
    
    RTC_Timer() : /*Constructor for real-time clock object*/
	timer_state(false), second(0), minute(0), hour(0), day(0)
    {
        set_time(0);
    }


	void Reset() /*Reset clock to zero*/
    {
        timer_state = true;
        set_time(0);
        second = 0;
        minute = 0;
        hour = 0;
        day = 0;
    }


	void Off() /*Disable clock but still hold it's value*/
    {
        timer_state = false;
    }


	void On() /*Resume clock*/
    {
        timer_state = true;
    }


	void ChangeState() /*Toggle clock's state*/
    {
        timer_state = !timer_state;
    }

   
	bool GetState()	/*Get clock's state*/
    {
        return timer_state;
    }
	
	void Update()	/*Update timer*/
    {
        /* Update timer*/
        seconds = time(NULL); 
        second = seconds % 60;
        minute = seconds % 3600 / 60;
        hour = seconds % 86400 / 3600;
    }

	int GetSecond() 
    {
        return second;
    }

    int GetMinute()
    {
        return minute;
    }

    int GetHour()
    {
        return hour;
    }
	
    uint32_t GetSecond_s()
    {
        return time(NULL);
    }

private:
    bool timer_state;
    uint8_t second, minute, hour, day;
    uint32_t seconds;
	
};
#endif /*_RTCTIMER_H_*/
