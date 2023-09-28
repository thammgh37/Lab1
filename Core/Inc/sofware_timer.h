/*
 * sofware_timer.h
 *
 *  Created on: Sep 9, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFWARE_TIMER_H_
#define INC_SOFWARE_TIMER_H_

extern int timer_flag;
extern int timer_flag1;
extern int timer_flag2;

void timerRun();
void setTimer(int duration);
void setTimer1(int duration);
void setTimer2(int duration);

#endif /* INC_SOFWARE_TIMER_H_ */
