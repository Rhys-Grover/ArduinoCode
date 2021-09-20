
#define echoPin 10
#define trigPin 9

void setup() {

Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
int distance = msToCm( getDistance() );
Serial.print(distance);
Serial.println(" cm");
Serial.println("-----");
delay(200);
}

long getDistance() {
long duration;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
return duration;
}

long msToCm(long microseconds) {
return microseconds / 29 / 2;
}