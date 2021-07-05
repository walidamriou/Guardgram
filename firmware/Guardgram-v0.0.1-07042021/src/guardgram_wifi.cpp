
#include "guardgram_wifi.h"

WiFiClientSecure clientTCP;

// WiFi Credentials
const char* ssid     = guardgram_wifi_ssid;
const char* password = guardgram_wifi_password;

void Guardgram_Wifi_Connect(){
      // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("ESP32-CAM IP Address: ");
  Serial.println(WiFi.localIP()); 
}