/*
 * Develop.h
 *
 *  Created on: 08.11.2016
 *      Author: t.linz
 */

#ifndef DEVELOP_H_
#define DEVELOP_H_

#define DEVELOP 1 //indicates a development version

#define TIMEZONE "TZ=MEZ-1MESZ"

#if DEVELOP
    #define REBOOT_STRING "Reboot!!! Starting at %s\n"
    #define LED_TEST 0 // does a simple LED test at startup
    #define DISPLAY_TEST_SPEED 0xFFFFFFF //the higher the slower
    #define NO_DEBUGGER 0 // only map file debugging
    #define DEBUG_SYSTICK_EVERY_X_SECONDS 0 // Print Debug info every x seconds, or no output if 0
    #define DEBUG_DEVICE_TIME 1 // prints the device time every minute
    #define SET_DEVICE_TIME 0  // sets the device time to this timestamp. Reboot required after startup
#else
    #define NDEBUG // kein assert()-Output
#endif


#endif /* DEVELOP_H_ */
