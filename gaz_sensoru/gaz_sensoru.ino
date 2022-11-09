#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

char auth[] ="Mi2aeSmQWmdwiQRwz7ooboF4L7iFeB92";
char ssid[] ="HUAWEI Mate 20 lite";
char pass[] ="13122000";

BlynkTimer timer;

int GazSensoru = A0;
int data=0;
#define BirinciLed 14
#define IkinciLed 12

int buzzer =0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);  
  pinMode(BirinciLed, OUTPUT);
  pinMode(IkinciLed, OUTPUT);
  timer.setInterval(1000L, getSendData);             

}

void loop() {
  timer.run();
  Blynk.run();

}
void getSendData (){
  data= analogRead(GazSensoru);
  Blynk.virtualWrite(V2, data);
  
  if (data>340){
    Blynk.notify("Dikkat! Gaz sensörü devrede");
    digitalWrite (BirinciLed, LOW);
    digitalWrite (IkinciLed, HIGH);
    tone(buzzer, 1000, 200);
    
    }
  else {
    digitalWrite(BirinciLed, HIGH);
    digitalWrite(IkinciLed, LOW);
    noTone(buzzer);
    } 
















  
  }
