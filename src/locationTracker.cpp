#include <Notecard.h>
#include "locationTracker.h"

// the setup function runs once when you press reset or power the board
void setupLocationTracker(
    Notecard &notecard,
    double outboundSyncMinutes,
    double inboundSyncMinutes,
    double gpsPeriodMinutes,
    double heartbeatHoursWhenStationary)
{
    J *req = notecard.newRequest("hub.set");
    JAddStringToObject(req, "mode", "periodic");
    JAddNumberToObject(req, "outbound", outboundSyncMinutes);
    JAddNumberToObject(req, "inbound", inboundSyncMinutes);
    notecard.sendRequest(req);

    req = notecard.newRequest("card.location.mode");
    JAddStringToObject(req, "mode", "periodic");
    JAddNumberToObject(req, "seconds", gpsPeriodMinutes * 60);
    notecard.sendRequest(req);

    req = notecard.newRequest("card.location.track");
    JAddBoolToObject(req, "sync", true);
    JAddBoolToObject(req, "heartbeat", true);
    JAddNumberToObject(req, "hours", heartbeatHoursWhenStationary);
    notecard.sendRequest(req);
}

// the loop function runs over and over again forever
void loopLocationTracker()
{
}