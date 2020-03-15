// /*========================================================================

// To manage Wifi Functions of Esp8266

// ========================================================================*/

// #include <WifiConnection.h>
// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>

// #include <MiscFunc.h>

// // ------------------------- global Declaraions -------------------------

// WifiConnectionClass WifiConnection;

// // connection info
// const char* ssid = "Ezhack";
// const char* password = "33333333";
// const char* mqtt_server = "149.28.177.218"; //turtle - main
// //const char* mqtt_server = "149.28.180.60";    //leo - testing
// // something
// WiFiClient espClient;
// PubSubClient client(espClient);

// // ------------------------- Functions ---------------------------------


// //connection func
// void WifiConnection::setup_wifi(){ 
// delay(10);
//   // We start by connecting to a WiFi network
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) { // if not connected print . every .5s
//     delay(120);
//     Serial.print(".");

//     MiscFunc.LEDLoading(120);
//   }

//   randomSeed(micros());

//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// // whats callback
// void WifiConnection::callback(char* topic, byte* payload, unsigned int length){
//   Serial.print("Message arrived [");
//   Serial.print(topic);
//   Serial.print("] ");
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]);
//   }
//   Serial.println();

//   // Switch on the LED if an 1 was received as first character
//   if ((char)payload[0] == '1') {
//     digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
//     // but actually the LED is on; this is because
//     // it is active low on the ESP-01)
//   } else {
//     digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
//   }
// }

// //reconenct
// void WifiConnection::reconnect(){
//   // Loop until we're reconnected
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
//     // Create a random client ID
//     String clientId = "ESP8266Client-";
//     clientId += String(random(0xffff), HEX);
//     // Attempt to connect
//     if (client.connect(clientId.c_str())) {
//       Serial.println("connected");
//       // Once connected, publish an announcement...
//       client.publish("outTopic", "hello world");
//       // ... and resubscribe
//       client.subscribe("inTopic");
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       // Wait 5 seconds before retrying
//       delay(5000);
//     }
//   }
// }



// // ------------------------- End ---------------------------------