//LCD Initialize:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
// Traffic lights - side A
#define LEDGreen 4
#define LEDYellow 1
#define LEDRed 0
// Traffic lights - side B
#define LEDGreenA 10
#define LEDYellowA 9
#define LEDRedA 8
// Pedestrian button and lights
#define PedestrianLEDGreen 6
#define PedestrianLEDRed 7
#define PedestrianButton 12
// Buzzer
#define Buzzer 11

int waitTime = 0;
bool ButtonPressed = false;
unsigned long lastBuzzTime = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  while(!Serial)
  {
    ;
  }
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDRed, OUTPUT);
  pinMode(Buzzer,OUTPUT);


  pinMode(LEDGreenA, OUTPUT);
  pinMode(LEDYellowA, OUTPUT);
  pinMode(LEDRedA, OUTPUT);
  pinMode(PedestrianLEDGreen, OUTPUT);
  pinMode(PedestrianLEDRed, OUTPUT);
  pinMode(PedestrianButton, INPUT);

/*test(LEDGreen);
test(LEDYellow);
test(LEDRed);
test(LEDGreenA);
test(LEDYellowA);
test(LEDRedA);*/

//Start LCD:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Wait before cross:");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PedestrianLEDRed, HIGH);
  Serial.println(digitalRead(PedestrianButton));
  digitalWrite(Buzzer, HIGH);
  digitalWrite(Buzzer, LOW);
  delay(1000);
  if(digitalRead(PedestrianButton) == HIGH)
  {
    ButtonPressed = true;
    waitTime = 20;
  }

//Countdown Display if Button Pressed
  while(waitTime>0 && ButtonPressed)
  {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(waitTime);
    lcd.print("s ");
    delay(1000);
    waitTime--;
  }
//Timer Countdown
  if(ButtonPressed == true)
  {
    digitalWrite(PedestrianLEDRed, LOW);
    digitalWrite(PedestrianLEDGreen, HIGH);
    lcd.clear();
    delay(5000); // Allow pedestrians to cross for 5 seconds
    digitalWrite(PedestrianLEDGreen, LOW);
    digitalWrite(PedestrianLEDRed, HIGH);
    ButtonPressed = false;
    lcd.print("Wait before cross:");
  }
  // Buzzer sound for blind people

  while (ButtonPressed == true) 
  {
    unsigned long currentTime = millis();
    if (digitalRead(PedestrianLEDRed) == HIGH) 
    {
      if (currentTime - lastBuzzTime >= 1000) 
      {
        digitalWrite(Buzzer,HIGH);
        delay(50);
        digitalWrite(Buzzer,LOW);
        lastBuzzTime = currentTime;
      }
    } 
    else 
    {
      if (currentTime - lastBuzzTime >= 500) 
      {
        digitalWrite(Buzzer,HIGH);
        delay(50);
        digitalWrite(Buzzer,LOW);
        lastBuzzTime = currentTime;
      }
    }
  }
  //TrafficLights();

/* Toby's kode
digitalWrite(LEDRedA,HIGH);
digitalWrite(LEDRed, LOW);
delay(5000);

digitalWrite(LEDGreen,LOW);
digitalWrite(LEDYellow,HIGH);
delay(3000);

digitalWrite(LEDYellow,LOW);
digitalWrite(LEDRed,HIGH);
digitalWrite(LEDGreenA,HIGH);
digitalWrite(LEDRedA, LOW);
delay(10000);

digitalWrite(LEDGreenA,LOW);
digitalWrite(LEDYellowA,HIGH);
digitalWrite(LEDRedA, HIGH);
delay(3000);

digitalWrite(LEDYellowA,LOW);
digitalWrite(LEDRedA,LOW);
digitalWrite(LEDGreen,HIGH);
*/

}

void TrafficLights()
{
  // Starting point
  digitalWrite(LEDRed, HIGH);
  digitalWrite(LEDRedA, HIGH);
  delay(1500);
  // Start execution - side A
  digitalWrite(LEDYellow, HIGH);
  delay(3000);
  // Green - side A
  digitalWrite(LEDRed, LOW);
  digitalWrite(LEDYellow, LOW);
  digitalWrite(LEDGreen, HIGH);
  delay(5000);
  // Green -> yellow - side A
  digitalWrite(LEDGreen, LOW);
  digitalWrite(LEDYellow, HIGH);
  delay(2000);
  // Yellow -> Red - side A
  digitalWrite(LEDYellow, LOW);
  digitalWrite(LEDRed, HIGH);
  delay(3000);

  // Start execution - side B
  digitalWrite(LEDYellowA, HIGH);
  delay(3000);
  // Red and Yellow ON - side B
  digitalWrite(LEDRedA, LOW);
  digitalWrite(LEDYellowA, LOW);
  digitalWrite(LEDGreenA, HIGH);
  delay(10000);
  // Green -> yellow - side B
  digitalWrite(LEDGreenA, LOW);
  digitalWrite(LEDYellowA, HIGH);
  delay(2000);
  // Yellow -> Red - side B
  digitalWrite(LEDYellowA, LOW);
  digitalWrite(LEDRedA, HIGH);
  delay(5000);

  // Buzzer sound for blind people
  if (ButtonPressed && waitTime == 0) {
    digitalWrite(PedestrianLEDRed,LOW);
    digitalWrite(PedestrianLEDGreen,HIGH);
  } else {
    digitalWrite(PedestrianLEDGreen,LOW);
    digitalWrite(PedestrianLEDRed,HIGH);
  }

  while (true) {
    unsigned long currentTime = millis();
    if (digitalRead(PedestrianLEDGreen) == HIGH) {
      if (currentTime - lastBuzzTime >= 500) {
        digitalWrite(Buzzer,HIGH);
        delay(50);
        digitalWrite(Buzzer,LOW);
        lastBuzzTime = currentTime;
      }
    } else {
      if (currentTime - lastBuzzTime >= 1000) {
        digitalWrite(Buzzer,HIGH);
        delay(50);
        digitalWrite(Buzzer,LOW);
        lastBuzzTime = currentTime;
      }
    }
  }
}

void Pedestrians()
{

}
int test(int LED)
{
  digitalWrite(LED, HIGH);
}

int LEDon(int LED)
{
  digitalWrite(LED, HIGH);
}
int LEDoff(int LED)
{
  digitalWrite(LED, LOW);
}
