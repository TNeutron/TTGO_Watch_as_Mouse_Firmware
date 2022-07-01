
#define WLAN_SSID "SATL"
#define WLAN_PASS "SATL4321"

void connect_to_internet_Try_n_Times(int n) {

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  Serial.print("Connecting to WiFi ..");

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