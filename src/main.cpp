#include <Arduino.h>
#include <Notecard.h>

#include "config.h"

#include "commsNotecard.h"
#include "locationTracker.h"
#include "swanBlinker.h"

// the setup function runs once when you press reset or power the board
void setup()
{
  Notecard &notecard = setupComms(productUID);
  setupLocationTracker(notecard, outboundSyncMinutes, inboundSyncMinutes, gpsPeriodMinutes, heartbeatHoursWhenStationary);
  setupBlinker();
}

// the loop function runs over and over again forever
void loop()
{
  loopComms();
  loopLocationTracker();
  loopBlinker();
}