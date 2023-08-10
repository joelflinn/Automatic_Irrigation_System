/*
-------------------------------------------------
PROGRAM NAME - Automatic Irrigation System

PROGRAMMER - Joel Flinn

SYSTEM - Arduino Uno R3

Components - This program is compatible with a system that
             uses: An Arduino Uno R3, 5v relay, capacitive
             soil moisture sensor v2.0, 12v water pump 

DATE - Project Started: 7-3-23
       Project finished: 8-3-23

Modifications - Moisture Sensor testing: 7-17-23
                Relay component testing: 7-19-23

DESCRIPTION - This Program records data relating to the 
moisture of a potted plant and then determines whether a 
signal should be sent to a relay to turn it on or off.
The relay allows for power to be provided to a water pump.
-------------------------------------------------
*/


//macros for pin setup
# define SENSORPIN A0
# define RELAYPIN 6

//parameters for soil moisture sensor
# define TOOWET 450
# define TOODRY 600

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);

  // setup for the relay pin, set to off
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, HIGH);
}

void loop() {

  // Read the Analog Input
  int value = analogRead(SENSORPIN);
  
  // Print the value to the serial monitor
  Serial.print("Analog output: ");
  Serial.println(value);
  

  // multi way if statement to decided if the pump
  //should be turned on or if the pump should be turned/ remain off

  //soil is too dry
  if(value > TOODRY){

    //print a message
    Serial.println("this plant needs watering");
    Serial.println();

    //turn on the water pump
    digitalWrite(RELAYPIN, LOW);

  }
  
  //ideal soil conditions
  else if((value <= TOODRY) && (value >= TOOWET)){
    Serial.println("the soil is perfect");
    Serial.println();
  }

  else if(value < TOOWET){
    //printing a message
    Serial.println("the soil is saturated");
    Serial.println();

    //turning or keeping the relay off
    digitalWrite(RELAYPIN, HIGH);
  }

  // Wait for 1 second before the next reading
  delay(1000);

}
