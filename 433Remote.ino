/*
* RF 433 Remote control
*
* Setup:
* - Connect a 433MHz transmitter to digital pin 11.
* - send orders using serial from PC
*   int XYYZ
*   X : 0 and 7 to 9 are unassigned
*   X : 1 to 6 is for RF remote
*   YY: is the decimal letter A to F are supported (65(A) to 70(F))
*   Z : even if ON, odd is OFF
*/
#include <RemoteTransmitter.h>

// Intantiate a new elroTransmitter remote, use pin 11
ElroTransmitter elroTransmitter(11);

void setup() {
  // initialize serial:
  Serial.begin(115200);
  Serial.println("starting");
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    Serial.print("input ");
    Serial.println(red);
    int remote_number = red / 1000;      // 1 to 6 is supported
    int remote_switchOnOff = red % 2;    // 0 if off // 1 is on
    int remote_letter = (red - remote_number * 1000) / 10;
    boolean switchOnOff;
    if ( remote_switchOnOff == 1 ) { switchOnOff = true; } else { switchOnOff = false;}

    elroTransmitter.sendSignal(remote_number,char(remote_letter),switchOnOff);
    Serial.print(remote_number);
    Serial.print(" ");
    Serial.print(char(remote_letter));
    Serial.print(" ");
    Serial.println(switchOnOff);
  }
}
