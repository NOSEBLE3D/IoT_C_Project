int led =2;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
 pinMode(led, OUTPUT); // declare pwm pin to be an output:
}

void loop() {
 analogWrite(led, brightness); // set the brightness of led

 // change the brightness for next time through the loop:
 brightness = brightness + fadeAmount;

 // reverse the direction of the fading at the ends of the fade:
 if (brightness <= 0 || brightness >= 255) {
   fadeAmount = -fadeAmount;
 } 
 delay(30);  // wait for 30 milliseconds to see the dimming effect
}