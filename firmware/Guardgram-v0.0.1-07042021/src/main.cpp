/**
 * @file main.cpp
 * @brief Main file of Guardgram firmware source by Arduino 
 * 
 * @author Walid Amriou
 * @date 07/04/2021
 * 
 * Guardgram 
 * Controlling ESP32-CAM via Telegram bot ( take and send photos ) 
 * Source: https://github.com/walidamriou/Guardgram
 * 
 * Firmware Version 0.0.1 
 * 
 */

#include "guardgram_includes.h"


void setup(){
  // General initializations
  Guardgram_Init();

  // Config and init the camera
  Guardgram_Camera_Config();
  
  // Config WiFi connection
  Guardgram_Wifi_Connect();

}

void loop(){
  Guardgram_Core();
}

