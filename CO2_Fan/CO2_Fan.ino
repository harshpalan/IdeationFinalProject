// Tutorial "Interfacing SGP30 CO2 & TVOC Sensor with Arduino" from https://how2electronics.com/interfacing-sgp30-co2-tvoc-sensor-with-arduino/
// Tutorial "Arduino RGB LED" from https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
// Tutorial "Arduino - DC Motor" from https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm
#include "SparkFun_SGP30_Arduino_Library.h" 
#include <Wire.h>
 
SGP30 mySensor; //create an object of the SGP30 class
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;
int motorPin = 3;
 
void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  //Initialize sensor
  if (mySensor.begin() == false) 
  {
    Serial.println("No SGP30 Detected. Check connections.");
    while (1);
  }
  //Initializes sensor for air quality readings
  //measureAirQuality should be called in one second increments after a call to initAirQuality
  mySensor.initAirQuality();
  Serial.println("SGP30 connected.");
  // setup LED
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
 
void loop() 
{
  //First fifteen readings will be
  //CO2: 400 ppm  TVOC: 0 ppb
  delay(1000); //Wait 1 second
  //measure CO2 and TVOC levels
  mySensor.measureAirQuality();
  Serial.print("CO2: ");
  Serial.print(mySensor.CO2);
  Serial.println(" ppm");
  // digitalWrite(motorPin, HIGH);
      
  // if (mySensor.CO2 <= 500){
  //   RGB_color(0, 255, 0); // Green
  //   digitalWrite(motorPin, LOW);
  // }else if(mySensor.CO2 <= 800){
  //   RGB_color(255, 255, 0); // Yellow
  //   digitalWrite(motorPin, HIGH);
  // }else{
  //   RGB_color(255, 0, 0); // Red
  //   digitalWrite(motorPin, HIGH);
  // }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}