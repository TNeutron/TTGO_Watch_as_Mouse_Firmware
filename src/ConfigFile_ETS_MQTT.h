
// MQTT Configs
#define AIO_SERVER "103.36.102.76" //"65.2.95.142"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME "iotmate"
#define AIO_KEY "hYvgo0-nyxpym-nyshyn"

// MQTT Subscribe Address | Example: iotmate/ETS_12/response

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME,
                          AIO_KEY);

Adafruit_MQTT_Publish ETS = Adafruit_MQTT_Publish(&mqtt, "iotmate/python/mqtt");

/*  String MQTT_sub = "iotmate/ETS_" + ets_code + "/response";
Adafruit_MQTT_Subscribe ETS_Reply =
    Adafruit_MQTT_Subscribe(&mqtt, MQTT_sub.c_str()); 

 
String MQTT_sub_stats = "iotmate/ETS_" + ets_code + "/response";
Adafruit_MQTT_Subscribe ETS_Stats =
    Adafruit_MQTT_Subscribe(&mqtt, MQTT_sub_stats.c_str());
 */ 

/**
 * @brief Checks if MQTT is connected,
 *        Tried to connect if not connected.
 */
void MQTT_connect() {
  int8_t ret;
  if (mqtt.connected())
    return;
  while ((ret = mqtt.connect()) != 0) {
    delay(10);
    mqtt.disconnect();
  }
  Serial.println("MQTT Connected!");

  ttgo->tft->setTextSize(2);
  ttgo->tft->setCursor(0, 10);
  ttgo->tft->print("Connected");

  delay(1000);
}

bool Check_MQTT_Connectivity() {
  if (mqtt.connected())
    return true;
  else
    return false;
}

void Connect_To_MQTT() {
  Serial.print("Connecting to MQTT... ");
  delay(10);

  int MQTTConnect = mqtt.connect();
  while (MQTTConnect !=
         0) { // mqtt.connect() returns 0 on successful connection
    Serial.println(mqtt.connectErrorString(MQTTConnect));
    Serial.println("Retrying MQTT connection...");
    delay(1500);
    mqtt.disconnect();
  }
  Serial.println("MQTT Connected!");
  delay(10);
}

void MQTT_Publish(String Mqtt_data) {
  int len = Mqtt_data.length() + 1;
  char char_arr[len];
  Mqtt_data.toCharArray(char_arr, len);
  ETS.publish(char_arr);
}