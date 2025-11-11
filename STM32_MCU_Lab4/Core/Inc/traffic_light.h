/*
 * traffic_light.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ASUS
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

/* Includes */
#include "main.h"

/* Define */
#define ON		1
#define OFF		0

/* Variables */

/* Functions */
// Control the traffic light on way 1 (vertical)
void setLightWay1(int red, int yellow, int green);
// Control the traffic light on way 2 (horizontal)
void setLightWay2(int red, int yellow, int green);

void setAllRedLED(int LEDstatus);
void setAllYellowLED(int LEDstatus);
void setAllGreenLED(int LEDstatus);

#endif /* INC_TRAFFIC_LIGHT_H_ */
