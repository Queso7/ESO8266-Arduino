#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2      
#define DHTTYPE DHT11  
int VO = 3;
int RS = 4;
int E = 5;
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;

int humedad;
int temperaturaC;

DHT sensorDHT(DHTPIN, DHTTYPE);
LiquidCrystal lcd (RS, E, D4, D5 ,D6, D7);
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2); 
  analogWrite(VO, 50);
  sensorDHT.begin();
}

void loop() {
  delay(2000);
  humedad = sensorDHT.readHumidity();
  temperaturaC = sensorDHT.readTemperature();
  if ( isnan(humedad) || isnan(temperaturaC)) {
    return;   // Si hubo un error en la lectura, el programa sale,
              // reiniciando la función loop,
  }           // si no hubo error, el programa continúa.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(temperaturaC);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print("%");
  Serial.println(temperaturaC);
}
