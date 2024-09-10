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



}

void loop() {
  // put your main code here, to run repeatedly:








}

int test(int LED)
{
  digitalWrite(LED, HIGH);
}
