#include <LiquidCrystal.h>
// Setting LCD RS E D4 D5 D6 D7
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);
const int TRIG_PIN = 4;// pin triger sensor ultrasonic di koneksikan ke pin 12 pada arduino 
const int ECHO_PIN = 5;// pin echo sensor ultrasonic di koneksikan ke pin 11 pada arduino

void setup(){
// pilih LCD 16 x 2
Serial.begin(9600);
pinMode(TRIG_PIN,OUTPUT);
pinMode(ECHO_PIN,INPUT);
lcd.begin(16,2);
lcd.setCursor(2,0);
lcd.print("Deny Pradana");
lcd.setCursor(3,1);
lcd.print("ULTRASONIC");
delay(3000);
}

void loop(){
 long duration, distanceCm;

  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN,HIGH);

  // convert the time into a distance
  // 340 m/s--> dalam satu detik jarak tempuh adalah 340 meter, 
  //1/10 detik untuk 34 meter, 
  //1/100 detik (10 /1000 detik (baca 10 mili detik))untuk 3,4 meter 
  // 1/1000 detik baca 1 mili detik untuk jarak 0,34 meter (34cm)
  
 // jadi untuk menempuh jarak 1 cm --> (1/100 meter) diperlukan waktu sebanyak : 
  //29.1 ųs/cm
  distanceCm = duration / 29.41 / 2 ;

  if (distanceCm <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distanceCm);
    Serial.println("CM");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jarak");
  lcd.setCursor(0, 1);
  lcd.print(distanceCm);
  lcd.print(" Cm ");
  
  }
  delay(1000);
}
