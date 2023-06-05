//=========================TIME=========================
#include <TimeLib.h>
String waktu, hari;
//=========================millis=========================
unsigned long previousMillisShowTime = 0;
const long intervalShowTime = 1000;    

void setup() {
  setTime(15,43,0,26,5,2023);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisShowTime >= intervalShowTime) {
    previousMillisShowTime = currentMillis;
      digitalClockDisplay();  
  }
}
void digitalClockDisplay(){
  hari = String(day()) + "/" + String(month()) + "/" + String(year());
  waktu = String(hour()) + ":" + String(minute()) + ":" + String(second());
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print("/");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
