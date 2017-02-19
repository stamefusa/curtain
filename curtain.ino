int dig1 = 12, dig2 = 13, dig3 = 7, dig4 = 8;
int pwm1 = 11, pwm2 = 6;
String str = "";

void setup(){
  Serial.begin(9600);
  pinMode(dig1,OUTPUT);
  pinMode(dig2,OUTPUT);
  pinMode(dig3,OUTPUT);
  pinMode(dig4,OUTPUT);
  stopMotor();
}

void loop(){
  if (Serial.available() > 0) {
    str = Serial.readStringUntil('\r');
    if (str == "a") {
      normal1(100);
    } else if (str == "s") {
      reverse1(100);
    } else if (str == "z") {
      normal2(100);
    } else if (str == "x") {
      reverse2(100);
    } else if (str == "q") {
      dropCurtain();
    }
    delay(200);
  }
  stopMotor();
}

void stopMotor()
{
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, LOW);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}

void normal1(int num)
{
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, HIGH);
  analogWrite(pwm1, num);
}

void reverse1(int num)
{
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, LOW);
  analogWrite(pwm1, num);
}

void normal2(int num)
{
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, HIGH);
  analogWrite(pwm2, num);
}

void reverse2(int num)
{
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, LOW);
  analogWrite(pwm2, num);
}

void dropCurtain()
{
  normal2(200);
  reverse1(200);
  delay(1000);
}
