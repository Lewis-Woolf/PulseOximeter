int inPin = 10; // Pin for the heart rate reading
long timerLength = 10000; // Length of timer for heart rate count
long currentTimerCount = 0; // Counter for the current time
long initialTimerCount = 0; // Counter which increases in increments of timerLength
int beatCount = 0; // Sets the heartbeat count to 0 initially

float thresholdVoltage = 5e-3; // Threshold voltage to count heart rate


void setup() {

}

void loop() {
  currentTimerCount = millis();

  if (currentTimerCount - initialTimerCount >= timerLength) { // If an amount of time equal to timerlength has passed, initial timer is set to a multiple of timer length
    initialTimerCount = millis();
    beatCount = 0;
  }

  float Voltage = analogRead(inPin); //Read the voltage
  if (Voltage >= thresholdVoltage) { // When threshold voltage is reached, add 1 to the heartbeat counter
    beatCount += 1;
  }
}
