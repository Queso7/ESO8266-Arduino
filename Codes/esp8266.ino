#include <ESP8266WiFi.h>
#include <WiFIClient.h>

#define lv 5
#define la 4
#define lA 0
#define rel 13

int inf, aux;

void actb(){

}
void inwifi(){
  WiFi.begin("ssid", "pwd");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print('.');
    digitalWrite(lA, HIGH);
    delay(100);
    digitalWrite(lA, LOW);
    delay(100);
  }
    digitalWrite(lv, HIGH);
    delay(200);
    digitalWrite(lv, LOW);
    delay(200);
    digitalWrite(lv, HIGH);
    delay(200);
}
String get_t(){
  WiFiClient client;
  HTTPClient http;  
  String timeS = "";
  http.begin(client, "http://worldtimeapi.org/api/timezone/America/Mexico_City");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
    String payload = http.getString();
    int beginS = payload.indexOf("datetime");
    int endS = payload.indexOf("day_of_week");
    timeS = payload.substring(beginS + 22, endS - 16);    
  }
  return timeS;
}
void instat(){ 
  digitalWrite(lv,LOW);
  digitalWrite(lA,LOW);
  digitalWrite(la,LOW);
  digitalWrite(rel,HIGH);
}

void setup(){
  Serial.begin(115200);
  pinMode(lv, OUTPUT);
  pinMode(lA, OUTPUT);
  pinMode(la, OUTPUT);
  pinMode(rel, OUTPUT);
  instat();
  inwifi();
}

void loop(){
  String t = get_t();
  inf = 0;
  while(Serial.available()>0){
    aux=Serial.read();
    if(aux >= 48 && aux <= 57){
      inf = inf*10;
      inf = inf+(aux-48);
    }
  }
  Serial.println(inf);
  Serial.println(WiFi.localIP());
  Serial.println(t);
  delay(2000);
 } 
