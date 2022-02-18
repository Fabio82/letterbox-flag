#include <SharpDistSensor.h>
#include <Servo.h>

// Analog pin to which the sensor is connected
const byte sensorPin = A0;

// Window size of the median filter (odd number, 1 = no filtering)
const byte medianFilterWindowSize = 5;

// Create an object instance of the SharpDistSensor class
SharpDistSensor sensor(sensorPin, medianFilterWindowSize);

Servo myservo;  // create servo object to control a servo

int distance;

void setup() {
  Serial.begin(9600);

  // Set sensor model
  sensor.setModel(SharpDistSensor::GP2Y0A51SK0F_5V_DS);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.println("inizializzazione completata ...");
}

void loop() {
  // Get distance from sensor
  distance = sensor.getDist();

  // Print distance to Serial
  distance = map(distance, 18, 190, 180, 55);
  myservo.write(distance);
  Serial.println(distance);
  delay(15);
}

