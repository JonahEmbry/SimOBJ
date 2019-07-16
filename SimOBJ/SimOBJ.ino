/*
        Arduino Reciever Simulator
     by Jonah Embry, https://embryindustries.weebly.com

     This starts up the ESC, sets the throttle to zero, then spins the motor for 5 seconds, afterwhich it powers the motor back down. 
     This is the duration of the program
*/
#include <Servo.h>
Servo ESC;     // create servo object to control the ESC
int value = 0; // Value for spinning motor 
int flag = 0; // flag variable

void setup() {
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);     //Start Serial
}
void loop() {

  ESC.write(value);    // Send the signal to the ESC
  Serial.write("0 \n");    // Print 0 to serial monitor
  delay(5000);

  if(flag == 0)     // Makes it so the motor is only spun once
  {
    value = 50;     // Speed at which the motor is spun (Can be adjusted to spin motor faster [Value between 0 and 180])
    ESC.write(value); 
    Serial.write("value \n"); 
    delay(5000);
  }

  value = 0;
  flag = 1;
  
}
