/**
 * @file guardgram_core.cpp
 * @brief Core of Guardgram firmware source by Arduino 
 * 
 * @author Walid Amriou
 * @date 07/04/2021
 * 
 */

#ifndef __GUARDGRAM_CORE_H__
#define __GUARDGRAM_CORE_H__

#include "guardgram_includes.h"

// Checks for new messages every 1 second.
// Check for new Telegram messages every x number of seconds
extern int bot_Request_Delay;
extern unsigned long last_Time_Bot_Ran;

/**
 * @brief Init function of Guardgram
 * 
 * Put this function before the while(1) 
 * 
 */
void Guardgram_Init();

/**
 * @brief core function of Guardgram
 * 
 * Put this function the while(1) 
 * 
 */
void Guardgram_Core();



#endif

