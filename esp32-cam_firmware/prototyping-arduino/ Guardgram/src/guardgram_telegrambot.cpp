#include "guardgram_telegrambot.h"

// Telegram Bot Token
// from BotFather (@BotFather or t.me/BotFather)
String BOTtoken = guardgram_telegrambot_bottoken;  // your Bot Token (Get from Botfather)

// rom myidbot (@myidbot or t.me/myidbot)
String CHAT_ID = guardgram_telegrambot_chat_id;

// Create a bot with the token and client 
UniversalTelegramBot bot(BOTtoken, clientTCP);

// To know if the system should send the photo or not
// default is false
bool sendPhoto = false;

// MCU LED 
// default is low
bool flashState = LOW;

// handles what happens when new messages arrive
void Guardgram_Telegram_Bot_Handle(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);
  
  // It checks the available messages
  for (int i = 0; i < numNewMessages; i++) {
    // Get the chat ID
    String chat_id = String(bot.messages[i].chat_id);
    // If the chat_id is different from chat ID (CHAT_ID) on the system so 
    // ignore the message and wait for the next message
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    // If the chat id correct so it is valid user and then Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);
    
    // Save the name of the sender on from_name
    String from_name = bot.messages[i].from_name;

    // If user send /start then send there they welcome 
    if (text == "/start") {
      String welcome = "Welcome , " + from_name + "\n";
      welcome += "Use the following commands to interact with your guardgram \n";
      welcome += "/photo : takes a new photo\n";
      welcome += "/lamp : toggles Lamp \n";
      // Send user welcome page
      bot.sendMessage(CHAT_ID, welcome, "");
    }
    // If user send (choose) /lam then change Lamp status
    if (text == "/lamp") {
      flashState = !flashState;
      digitalWrite(FLASH_LED_PIN, flashState);
      Serial.println("Change Lamp state");
    }
    // If user send (choose) /photo so take a photo ans send it 
    if (text == "/photo") {
      sendPhoto = true;
      Serial.println("New photo request");
    }
  }
}


// Send photo to telegram
String Guardgram_Telegram_Bot_send_Photo() {
  const char* myDomain = "api.telegram.org";
  String getAll = "";
  String getBody = "";

  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();  
  if(!fb) {
    Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();
    return "Camera capture failed";
  }  
  
  Serial.println("Connect to " + String(myDomain));


  if (clientTCP.connect(myDomain, 443)) {
    Serial.println("Connection successful");
    
    String head = "--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"chat_id\"; \r\n\r\n" + CHAT_ID + "\r\n--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"photo\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    String tail = "\r\n--RandomNerdTutorials--\r\n";

    uint16_t imageLen = fb->len;
    uint16_t extraLen = head.length() + tail.length();
    uint16_t totalLen = imageLen + extraLen;
  
    clientTCP.println("POST /bot"+BOTtoken+"/sendPhoto HTTP/1.1");
    clientTCP.println("Host: " + String(myDomain));
    clientTCP.println("Content-Length: " + String(totalLen));
    clientTCP.println("Content-Type: multipart/form-data; boundary=RandomNerdTutorials");
    clientTCP.println();
    clientTCP.print(head);
  
    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    for (size_t n=0;n<fbLen;n=n+1024) {
      if (n+1024<fbLen) {
        clientTCP.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen%1024>0) {
        size_t remainder = fbLen%1024;
        clientTCP.write(fbBuf, remainder);
      }
    }  
    
    clientTCP.print(tail);
    
    esp_camera_fb_return(fb);
    
    int waitTime = 10000;   // timeout 10 seconds
    long startTimer = millis();
    boolean state = false;
    
    while ((startTimer + waitTime) > millis()){
      Serial.print(".");
      delay(100);      
      while (clientTCP.available()) {
        char c = clientTCP.read();
        if (state==true) getBody += String(c);        
        if (c == '\n') {
          if (getAll.length()==0) state=true; 
          getAll = "";
        } 
        else if (c != '\r')
          getAll += String(c);
        startTimer = millis();
      }
      if (getBody.length()>0) break;
    }
    clientTCP.stop();
    Serial.println(getBody);
  }
  else {
    getBody="Connected to api.telegram.org failed.";
    Serial.println("Connected to api.telegram.org failed.");
  }
  return getBody;
}