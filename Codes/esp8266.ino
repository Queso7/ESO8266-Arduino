#include<time.h>
#include<ESP8266WiFi.h>
#define lv 5
#define la 4
#define lA 0
#define rel 13
time_t t;
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
  time(&t);
  inf=0;
  while(Serial.available()>0){
    aux=Serial.read();
    if(aux>=48 && aux<=57){
      inf = inf*10;
      inf = inf+(aux-48);
    }
  }
  Serial.println(inf);
  Serial.println(WiFi.localIP());
  Serial.println(asctime(localtime(&t)));
  delay(2000);
 } 
