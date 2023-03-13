// Define Trig and Echo pins
const int trigPin = 6;
const int echoPin = 9;
const int stopLED = 11;
const int slowLED = 10;
const int goLED = 8;


void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
 
  // Set Trig pin as output and Echo pin as input
   pinMode(goLED, OUTPUT);
    pinMode(slowLED, OUTPUT);
     pinMode(stopLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
 
  // Send a pulse to Trig pin for 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long duration = pulseIn(echoPin, HIGH);



int distance = duration / 58;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

if((float)distance < 2.5){
  digitalWrite(stopLED, HIGH);
  digitalWrite(slowLED, LOW);
  digitalWrite(goLED, LOW);  
}
else if(distance < 7){
  digitalWrite(slowLED, HIGH);
  digitalWrite(stopLED, LOW);
  digitalWrite(goLED, LOW);  
}
else{
  digitalWrite(goLED, HIGH);
  digitalWrite(stopLED, LOW);
  digitalWrite(slowLED, LOW);
}
delay(500);

}
