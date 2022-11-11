#include <Arduino.h>
#include "swanBlinker.h"

// the setup function runs once when you press reset or power the board
void setupBlinker()
{
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loopBlinker()
{
    digitalWrite(LED_BUILTIN,
                 HIGH);             // turn the LED on (HIGH is the voltage level)
    delay(1);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(999);                     // wait for a second
}