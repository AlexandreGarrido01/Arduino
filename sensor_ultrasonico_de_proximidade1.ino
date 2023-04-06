// C++ code
//
#define LED 2
#define BUZZER 5

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,5);
}

void loop()
{
  float distanciaEmCm =  0.01723 * readUltrasonicDistance(4, 3);
  if(distanciaEmCm < 50){
  	digitalWrite(LED,HIGH);
    tone(BUZZER,2541,100);
  }else{
  	digitalWrite(LED,LOW);
    noTone(BUZZER);
  }
  delay(100); // Wait for 100 millisecond(s)
}