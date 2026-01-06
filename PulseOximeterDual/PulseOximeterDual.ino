// Make sure to install the MAX30100lib by OXullo Intersecans
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox; // High level interface to the sensor

int BPM = 0; // Heartbeats per min

long reportingPeriod = 5000; // Time between information being printed
long lastReportTime = 0; // Time since last report


void setup() 
{
  Serial.begin(9600);
  delay(2000); // Delay for 500 ms so the serial monitor works properly

  Serial.println("Initialising Dual-Wavelength Pulse Oximeter... ");

  // Check that the pulse oximeter is working
  if (!pox.begin()) {
    Serial.println("FAILURE");
  }
  else {
    Serial.println("SUCCESS");
  }

  // Register the callback for the beat detection function
  pox.setOnBeatDetectedCallback(onBeatDetected);
}


// Print text when beat detected
void onBeatDetected()
{
  Serial.println("Beat detected");
}


void loop() {
  pox.update(); // Update POX

  // Print heart rate and oxidation levels every reporting period
  if (millis() - lastReportTime > reportingPeriod)
  {
    Serial.println("--------------"); // Spacing
    Serial.print("BPM: "); // Print heart rate
    Serial.println(pox.getHeartRate());
    Serial.print("SpO2: "); // Print oxidation levels
    Serial.println(pox.getSpO2());
    Serial.println("--------------"); // Spacing

    lastReportTime = millis(); // Update report time so loop only runs once every reporting period
  }
}
