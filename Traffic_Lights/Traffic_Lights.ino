#define LEDGreen 4
#define LEDYellow 3
#define LEDRed 2
#define LEDGreenA 10
#define LEDYellowA 9
#define LEDRedA 8



void setup() {
  // put your setup code here, to run once:
pinMode(LEDGreen, OUTPUT);
pinMode(LEDYellow, OUTPUT);
pinMode(LEDRed, OUTPUT);

pinMode(LEDGreenA, OUTPUT);
pinMode(LEDYellowA, OUTPUT);
pinMode(LEDRedA, OUTPUT);

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

  // Starting point
  digitalWrite(LEDRed, HIGH);
  digitalWrite(LEDRedA, HIGH);
  delay(1500);
  // Start execution on side A
  digitalWrite(LEDYellow, HIGH);
  delay(3000);
  // Green on side A
  digitalWrite(LEDRed, LOW);
  digitalWrite(LEDYellow, LOW);
  digitalWrite(LEDGreen, HIGH);
  delay(5000);
  // Green -> yellow side A
  digitalWrite(LEDGreen, LOW);
  digitalWrite(LEDYellow, HIGH);
  delay(2000);
  // Yellow -> Red side A
  digitalWrite(LEDYellow, LOW);
  digitalWrite(LEDRed, HIGH);
  delay(3000);

  // Start execution on side B
  digitalWrite(LEDYellowA, HIGH);
  delay(3000);
  // Red and Yellow ON on side B
  digitalWrite(LEDRedA, LOW);
  digitalWrite(LEDYellowA, LOW);
  digitalWrite(LEDGreenA, HIGH);
  delay(10000);
  // Green -> yellow side B
  digitalWrite(LEDGreenA, LOW);
  digitalWrite(LEDYellowA, HIGH);
  delay(2000);
  // Yellow -> Red side B
  digitalWrite(LEDYellowA, LOW);
  digitalWrite(LEDRedA, HIGH);
  delay(5000);


/* Toby's kode
=======
digitalWrite(LEDGreen,HIGH);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
*/

}

int test(int LED)
{
  digitalWrite(LED, HIGH);
}

