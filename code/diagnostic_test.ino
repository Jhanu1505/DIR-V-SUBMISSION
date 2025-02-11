// Diagnostic Register & Internal Error Test
void loop() {
  Blynk.run();
  
  heartRate = particleSensor.getHeartRate();
  spO2 = particleSensor.getSpO2();
  if (heartRate > 0 && spO2 > 0) {
    lcd.clear();
    lcd.print("Heart Rate: ");
    lcd.print(heartRate);
    lcd.setCursor(0, 1);
    lcd.print("SpO2: ");
    lcd.print(spO2);
    Blynk.virtualWrite(V0, heartRate);
    Blynk.virtualWrite(V1, spO2);
  } else {
    lcd.clear();
    lcd.print("Fault Detected");
    lcd.setCursor(0, 1);
    lcd.print("Check Registers");
    Blynk.virtualWrite(V0, "Error");
    Blynk.virtualWrite(V1, "Error");
  }
  delay(1000);
}
