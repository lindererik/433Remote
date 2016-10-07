# RF 433 Remote control

using a simple 433MHz emitter to control plugs

## Dependencies

depends on https://bitbucket.org/fuzzillogic/433mhzforarduino

## Setup:
*  Connect a 433MHz transmitter to digital pin 11.
*  send orders using serial from PC
* *   int XYYZ
* *   X : 0 and 7 to 9 are unassigned
* *   X : 1 to 6 is for RF remote    
* *   YY: is the decimal letter A to F are supported (65(A) to 70(F))
* *   Z : even if ON, odd is OFF
