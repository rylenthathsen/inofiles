#include <Bildr-MLX90614.h>
#include <LiquidCrystal_I2C.h>
#define echoPin 12 //Echo Pin
#define trigPin 13 //Trigger Pin
#define LED1Pin 4 //Led default dari Arduino uno
#define LED2Pin 10 //Led default dari Arduino uno
#define buzzer 11
LiquidCrystal_I2C lcd(0x27, 16, 2);

MLX90614 sensor;

int maximumRange = 200; //kebutuhan akan maksimal range
int minimumRange = 00; //kebutuhan akan minimal range
long duration, distance; //waktu untuk kalkulasi jarak

void setup()
{
  Serial.begin(9600);
  Serial.println("Data Suhu MLX90614");
  lcd.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED1Pin, OUTPUT);
  pinMode(LED2Pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
 // float celsius = sensor.getC();
  //Serial.print("Suhu : ");
  //Serial.print(celsius);
  //Serial.print(" C");
  //delay(1000);

 // lcd.setCursor(0,0);
  //lcd.print(celsius);
  
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  float celsius = sensor.getC();

  if (celsius <= 37.00){
      digitalWrite(LED1Pin, HIGH);
    }else{
        digitalWrite(LED2Pin, HIGH);
      }

   lcd.setCursor (0,0);
   lcd.print("Suhu: ");
   lcd.setCursor (5,0);
   lcd.print(celsius);

   if(distance <= 10){
       digitalWrite(buzzer, HIGH);    
    }else {
        digitalWrite(buzzer, LOW);
       }
    lcd.setCursor (0,1);
    lcd.print("Jarak: ");
    lcd.setCursor (6,1);
    lcd.print(distance);
    delay(500);
    lcd.clear();
    
 //lcd.setCursor(0,1);
  //lcd.print(distance);
  
  
  //lcd.setCursor(0,1);
  //lcd.print(distance); 
  //delay(500); 
 // lcd.clear();
}
 
