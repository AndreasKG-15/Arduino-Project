
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

/*test(LEDGreen);
test(LEDYellow);
test(LEDRed);
test(LEDGreenA);
test(LEDYellowA);
test(LEDRedA);*/
  Serial.begin(9600);
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PedestrianButton) == HIGH && !ButtonPressed)
  {
    ButtonPressed = true;
    waitTime = 20;
  }
  TrafficLights();


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
