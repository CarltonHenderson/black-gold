#include <Notecard.h>
#include "commsNotecard.h"

#define usbSerial Serial

Notecard notecard;

Notecard &setupComms(const char *productUID)
{
    delay(2500);
    usbSerial.begin(115200);
    notecard.begin();
    notecard.setDebugOutputStream(usbSerial);

    J *req = notecard.newRequest("hub.set");
    JAddStringToObject(req, "product", productUID);
    notecard.sendRequest(req);

    return notecard;
}

void loopComms()
{
}