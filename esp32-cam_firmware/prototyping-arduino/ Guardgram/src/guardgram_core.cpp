#include "guardgram_core.h"

// Checks for new messages every 1 second.
// Check for new Telegram messages every x number of seconds
int bot_Request_Delay = guardgram_Telegram_messages_time_check;
unsigned long last_Time_Bot_Ran=0;

void Guardgram_Init(){
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  // Init Serial Monitor
  Serial.begin(115200);
  // Set LED Flash as output
  pinMode(FLASH_LED_PIN, OUTPUT);
  digitalWrite(FLASH_LED_PIN, flashState);
}

void Guardgram_Core(){
    if (sendPhoto) {
        Serial.println("Preparing photo");
        Guardgram_Telegram_Bot_send_Photo(); 
        sendPhoto = false; 
    }
    if (millis() > last_Time_Bot_Ran + bot_Request_Delay)  {
        int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
        while (numNewMessages) {
            Serial.println("got response");
            Guardgram_Telegram_Bot_Handle(numNewMessages);
            numNewMessages = bot.getUpdates(bot.last_message_received + 1);
        }
        last_Time_Bot_Ran = millis();
    }
}