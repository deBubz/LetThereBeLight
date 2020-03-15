
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <MiscFunc.h>
#include <LightSensor.h>



// connection info
const char* ssid = "Ezhack";
const char* password = "33333333";
const char* mqtt_server = "149.28.177.218"; //turtle - main
//const char* mqtt_server = "149.28.180.60";    //leo - testing
// something
WiFiClient espClient;
PubSubClient client(espClient);

// used in loop()
char data[3];
long lastMsg = 0;
int value = 0;


//------------------------------Func box-------------------------------
//connection func
void setup_wifi(){ 
delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { // if not connected print . every .5s
    delay(120);
    Serial.print(".");

    MiscFunc.LEDLoading(120);
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// whats callback
void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }
}

//reconenct
void reconnect(){
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
// -----------------------------------------------------------------------------

void setup(){

  Serial.begin(9600);
  
  MiscFunc.LEDInit();
  setup_wifi();



  LightSensor.BHInit();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {
  if (!client.connected()) {
    reconnect();

    MiscFunc.LEDLoading(50);
  } 
  client.loop();
  
long now = millis();
  if (now - lastMsg > 1000) { // do every 1000 ms
    lastMsg = now;
    ++value;

    LightSensor.BHReadingstoCharArr(data); // dtostrf(lux, 3,0, data); 
  
    char PAYLOAD[12] = "0bb0000bd"; // change this to your own prefix
  //concatenate(Payload, data)    // look at the concatenate() above
    MiscFunc.concatCharArr(PAYLOAD, data); //data is your readings /aaa/
    Serial.println(PAYLOAD); // check serial if your message is correct

    client.publish("b_light_sensor", PAYLOAD);  

    MiscFunc.LEDonRange();

  }
}   
