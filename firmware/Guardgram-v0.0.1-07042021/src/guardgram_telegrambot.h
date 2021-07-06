/**
 * @file guardgram_telegrambot.h
 * @brief Guardgram Telegram bot by Arduino Lang header file
 *
 *  
 * @author Walid Amriou
 * @date 07/04/2021
 * 
 * 
 */

#ifndef __GUARDGRAM_TELEGRAMBOT_H__
#define __GUARDGRAM_TELEGRAMBOT_H__

#include "guardgram_includes.h"

#define guardgram_telegrambot_bottoken "XXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define guardgram_telegrambot_chat_id  "XXXXXXXXXX"

#define guardgram_Telegram_messages_time_check 1000

void Guardgram_Telegram_Bot_Handle(int numNewMessages);
String Guardgram_Telegram_Bot_send_Photo();

extern WiFiClientSecure clientTCP;

// Telegram Bot Token
// from BotFather (@BotFather or t.me/BotFather)
extern String BOTtoken;  // your Bot Token (Get from Botfather)

// rom myidbot (@myidbot or t.me/myidbot)
extern String CHAT_ID;

extern UniversalTelegramBot bot;

// To know if the system should send the photo or not
// default is false
extern bool sendPhoto;

// MCU LED 
// default is low
extern bool flashState;
#endif