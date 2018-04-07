#include <Servo.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "xxx";
const char* password =  "xxx";
const char* mqttServer = "xxx.xxx.xx";
const int mqttPort = 1883;
const char* mqttUser = "xxx";
const char* mqttPassword = "xxx";
 
WiFiClient espClient;
PubSubClient client(espClient);
Servo servo;
 
void setup() {
 
  Serial.begin(115200);    
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("esp/test", "Hello from ESP8266");
  client.subscribe("esp/test");
  servo.attach(D1);
  servo.write(90);
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  if (payload[1]=='N') //ON
  {
    Serial.println("YES");
    servo.write(175);
    
  }
  else if (payload[1]=='F')
  {
    Serial.println("NO");
    servo.write(90);
  }
    
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  client.loop();
}
