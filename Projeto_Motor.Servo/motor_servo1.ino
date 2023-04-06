#include <Servo.h>
#define potenciometro A5
#define motor 2

Servo s;
  
void setup()
{
  pinMode(potenciometro, INPUT);
  s.attach(2);
  s.write(0);
}

void loop()
{
  int potencia = analogRead(potenciometro);
  float angulo = map(potencia, 0, 1023, 0, 180);
  s.write(angulo);
  delay(100);
}