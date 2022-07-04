
#define WLAN_SSID "SATL"
#define WLAN_PASS "SATL4321"

void connect_to_internet_Try_n_Times(int n) {

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  ttgo->tft->setTextSize(2);
  ttgo->tft->setCursor(0, 10);
  ttgo->tft->print("Connecting Wifi");

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(2000);
    attempts = attempts + 1;
    if (attempts > n) {
      ESP.restart();
    }
  }
}

bool Check_Wifi_Connectivity() {
  if (WiFi.status() != WL_CONNECTED) return false;
   else return true;
}