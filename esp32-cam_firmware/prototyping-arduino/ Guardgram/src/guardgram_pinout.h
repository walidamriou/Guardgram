/**
 * @file guardgram_pinout.h
 * @brief Guardgram pinout by Arduino Lang header file
 *
 *  
 * @author Walid Amriou
 * @date 07/04/2021
 * 
 * 
 */

#ifndef __GUARDGRAM_PINOUT_H__
#define __GUARDGRAM_PINOUT_H__

// the flash LED, for ESP32-CAM AI Thinker is GPIO 4
#define FLASH_LED_PIN 4

// ESP32-CAM AI-Thinker pins
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

#endif