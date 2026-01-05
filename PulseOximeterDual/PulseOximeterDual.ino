// Make sure to install the MAX30100lib by OXullo Intersecans
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox // High level interface to the sensor


void setup() 
{
  Serial.begin(9600);
  delay(500); // Delay for 500 ms so the serial monitor works properly

  Serial.print("Initialising Pulse Oximeter...");

  // Check that the pulse oximeter is working
  if (!pox.begin()) {
    Serial.println("FAILURE");
  }
  else {
    Serialprintln("SUCCESS");
  }
}

void loop() {

}
