const int trigPin = 13;   // Trigger pin of the ultrasonic sensor
const int echoPin = 12;   // Echo pin of the ultrasonic sensor
const int red = 3; // Red Led


void setup() {
  Serial.begin(9600);     // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  
}

void loop() {
  
  long duration, distance_cm;

  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance_cm = (duration / 2) * 0.0343;

  // Alert
  if (distance_cm <= 8)
  {
    
    digitalWrite(red, HIGH);
    
  }
  else{
    
     digitalWrite(red, LOW);
     
  }
  

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000);  // Delay before taking another measurement
}
