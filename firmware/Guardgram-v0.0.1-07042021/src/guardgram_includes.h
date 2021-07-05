/**
 * @file guardgram_includes.h
 * @brief Guardgram includes by Arduino Lang header file
 *
 *  
 * @author Walid Amriou
 * @date 07/04/2021
 * 
 * 
 */

#ifndef __GUARDGRAM_INCLUDES_H__
#define __GUARDGRAM_INCLUDES_H__

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#include "guardgram_wifi.h"
#include "guardgram_telegrambot.h"
#include "guardgram_pinout.h"
#include "guardgram_camera.h"
#include "guardgram_core.h"

#endif