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


// Variables
int GreenTimer = 5000;
int YellowTimer = 3000;
int RedTimer = 4000;
int waitTime = 0;
bool ButtonPressed = false;


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
  LEDon(PedestrianLEDRed);
  Serial.println(digitalRead(PedestrianButton));
  Pedestrians();
  //TrafficLights();
}

void TrafficLights()
{
  // Starting point
  LEDon(LEDRed);
  LEDon(LEDRedA);
  delay(1500);
  // Start execution - side A
  LEDon(LEDYellow);
  delay(3000);
  // Green - side A
  LEDoff(LEDRed);
  LEDoff(LEDYellow);
  LEDon(LEDGreen);
  delay(5000);
  // Green -> yellow - side A
  LEDoff(LEDGreen);
  LEDon(LEDYellow);
  delay(2000);
  // Yellow -> Red - side A
  LEDoff(LEDYellow);
  LEDon(LEDRed);
  delay(4000);

  // Start execution - side B
  LEDon(LEDYellowA);
  delay(3000);
  // Red and Yellow ON - side B
  LEDoff(LEDRedA);
  LEDoff(LEDYellowA);
  LEDon(LEDGreenA);
  delay(10000);
  // Green -> yellow - side B
  LEDoff(LEDGreenA);
  LEDon(LEDYellowA);
  delay(2000);
  // Yellow -> Red - side B
  LEDoff(LEDYellowA);
  LEDon(LEDRedA);
  delay(5000);
}

void Pedestrians()
{
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
    LEDoff(PedestrianLEDRed);
    LEDon(PedestrianLEDGreen);
    lcd.clear();
    delay(5000); // Allow pedestrians to cross for 5 seconds
    LEDoff(PedestrianLEDGreen);
    LEDon(PedestrianLEDRed);
    ButtonPressed = false;
    lcd.print("Wait before cross:");
  }
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
