// Make sure to install the MAX30100lib by OXullo Intersecans
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox // High level interface to the sensor

int BPM = 0; // Heartbeats per min

long currentTimerCount = 0; // Current time
long previousTimerCount = 0; // Time at last beat


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

  // Register the callback for the beat detection function
  pox.setOnBeatDetectedCallBack(onBeatDetected);
}


// When beat detected, calculate BPM
void onBeatDetected()
{
    currentTimerCount = millis(); // Set current timer count
    float timeDifference = (currentTimerCount - previousTimerCount) / 60000; // Time difference between previous and current count in minutes

    BPM = round(1 / timeDifference);

    previousTimerCount = millis(); // Set the previous timer count to the current time AFTER the BPM is calculated

    Serial.println("BPM: " + BPM);
}


void loop() {
}
