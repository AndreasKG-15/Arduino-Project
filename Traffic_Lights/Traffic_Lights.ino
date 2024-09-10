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

test(LEDGreen);
test(LEDYellow);
test(LEDRed);
test(LEDGreenA);
test(LEDYellowA);
test(LEDRedA);
  Serial.begin(9600);
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:








digitalWrite(LEDGreen,HIGH);
digitalWrite(LEDRedA,HIGH);
delay(5000);

digitalWrite(LEDGreen,LOW);
digitalWrite(LEDYellow,HIGH);
delay(3000);

digitalWrite(LEDYellow,LOW);
digitalWrite(LEDRed,HIGH);
digitalWrite(LEDGreenA,HIGH);
delay(10000);

digitalWrite(LEDGreenA,LOW);
digitalWrite(LEDYellowA,HIGH);
delay(3000)

digitalWrite(LEDYellowA,LOW);
digitalWrite(LEDRedA,LOW);
digitalWrite(LEDGreen,HIGH);


}
}
int test(int LED)
{
  digitalWrite(LED, HIGH);
}
