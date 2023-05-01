#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>


WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient); 

const int motionSensor = 27;
 // PIR Motion Sensor
#define buzzer_pin 18
bool motionDetected = false;

void IRAM_ATTR detectsMovement() {
   motionDetected = true;
}


const char* ssid = "nome_da_rede";
const char* password = "senha_da_rede";

char *mqttServer = "broker.hivemq.com";
int mqttPort = 1883;

void setupMQTT() {
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(callback);
}

void reconnect() {
  Serial.println("Conectando ao MQTT Broker...");
  while (!mqttClient.connected()) {
      Serial.println("Reconectando ao MQTT Broker..");
      String clientId = "ESP32Client-";
      clientId += String(random(0xffff), HEX);
      
      if (mqttClient.connect(clientId.c_str())) {
        Serial.println("Conectado.");
        // subscribe to topic
        mqttClient.subscribe("esp32/message");
      }      
  }
}

void setup() {
  Serial.begin(9600);


  pinMode(motionSensor, INPUT_PULLUP);
  // Configura o  motionSensor pin como interruptor e configura RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);
  pinMode(buzzer_pin, OUTPUT);
  
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    } 
    Serial.println("");
     Serial.println("Connected to Wi-Fi");

  setupMQTT();
}


void loop() {
  if (!mqttClient.connected())
    reconnect();
  mqttClient.loop();
    if(motionDetected){
      mqttClient.publish("esp32/motion", "motion detected!");
      //digitalWrite(buzzer_pin, HIGH); 
      tone(buzzer_pin, 1500);//Ligando o buzzer com uma frequência de 1500 Hz.
      delay(500);//Intervalo de 500 milissegundos
      noTone(buzzer_pin);           
      Serial.println("Motion Detected");
      motionDetected = false;
      
  }

}
  void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Callback - ");
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    
    Serial.print((char)message[i]);
  }
}