void setup() {
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
