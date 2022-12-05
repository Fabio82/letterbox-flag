#include <SharpDistSensor.h>
#include <Servo.h>

// Analog pin to which the sensor is connected
const byte sensorPin = A0;
const byte servoPin = 9;

// Window size of the median filter (odd number, 1 = no filtering)
const byte medianFilterWindowSize = 5;
const int boxHeight = 180; //ancora da misurare

// Create an object instance of the SharpDistSensor class
SharpDistSensor sensor(sensorPin, medianFilterWindowSize);
Servo myservo;

int distance;

void setup() {
  //Serial.begin(9600);

  // Set sharp IR sensor model
  sensor.setModel(SharpDistSensor::GP2Y0A51SK0F_5V_DS);
  myservo.attach(servoPin);
  //Serial.println("inizializzazione completata ...");

}

void rise_flag () {
  myservo.write(60);
}

void lower_flag () {
  myservo.write(160);
}

void loop() {
  myservo.attach(servoPin);
  distance = sensor.getDist();

  if ( distance <= boxHeight ) { rise_flag(); }
  else { lower_flag(); }
  

  //Serial.println(distance);

  delay(100);
}

