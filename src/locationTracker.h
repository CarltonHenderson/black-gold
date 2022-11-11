#ifndef LOCATION_TRACKER_H
#define LOCATION_TRACKER_H

#include <Notecard.h>

void setupLocationTracker(
    Notecard &notecard,
    double outboundSyncMinutes,
    double inboundSyncMinutes,
    double gpsPeriodMinutes,
    double heartbeatHoursWhenStationary);

void loopLocationTracker();

#endif