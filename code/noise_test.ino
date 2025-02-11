// Signal Integrity and Noise Test
void loop() {
  Blynk.run();
  
  heartRate = particleSensor.getHeartRate() + random(-5, 5);
  spO2 = particleSensor.getSpO2() + random(-2, 2);
  if (heartRate < 50) heartRate = 50;
  if (heartRate > 200) heartRate = 200;
  if (spO2 < 80) spO2 = 80;
  if (spO2 > 100) spO2 = 100;
  lcd.clear();
  lcd.print("Signal Noise");
  lcd.setCursor(0, 1);
  lcd.print("HR: ");
  lcd.print(heartRate);
  lcd.setCursor(0, 2);
  lcd.print("SpO2: ");
  lcd.print(spO2);
  Blynk.virtualWrite(V0, heartRate);
  Blynk.virtualWrite(V1, spO2);
  delay(1000);
}
