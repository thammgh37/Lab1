/*
 * software_timer.c
 *
 *  Created on: Sep 9, 2023
 *      Author: ADMIN
 */

#include "sofware_timer.h"

int timer_flag = 0;
int timer_flag1 = 0;
int timer_flag2 = 0;
int timer_counter = 0;
int timer_counter1 = 0;
int timer_counter2 = 0;

void setTimer(int duration){
	timer_flag = 0;
	timer_counter = duration;
}
void setTimer1(int duration){
	timer_flag1 = 0;
	timer_counter1 = duration;
}
void setTimer2(int duration){
	timer_flag2 = 0;
	timer_counter2 = duration;
}
void timerRun(){
	if (timer_counter > 0){
		timer_counter --;
		if (timer_counter <= 0){
			timer_flag = 1;
		}
	}
	if (timer_counter1 > 0){
		timer_counter1 --;
		if (timer_counter1 <= 0){
			timer_flag1 = 1;
		}
	}
	if (timer_counter2 > 0){
		timer_counter2 --;
		if (timer_counter2 <= 0){
			timer_flag2 = 1;
		}
	}
}
