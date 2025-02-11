// Functional Integrity Test (Sensor Response & Calibration Test)
#include <Wire.h>
#include <MAX30105.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

MAX30105 particleSensor;
int heartRate = 0;
int spO2 = 0;
bool isFaultInjected = false;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  Blynk.begin(auth, ssid, pass);
  
  if (!particleSensor.begin()) {
    lcd.clear();
    lcd.print("Sensor Error");
    Blynk.virtualWrite(V1, "Error");
    isFaultInjected = true;
  }
}

void loop() {
  Blynk.run();
  
  if (isFaultInjected) {
    heartRate = 0;
    spO2 = 0;
    lcd.clear();
    lcd.print("Fault Injected");
    lcd.setCursor(0, 1);
    lcd.print("HR: ");
    lcd.print(heartRate);
    lcd.setCursor(0, 2);
    lcd.print("SpO2: ");
    lcd.print(spO2);
    Blynk.virtualWrite(V0, "Error");
    Blynk.virtualWrite(V1, "Error");
  } else {
    heartRate = particleSensor.getHeartRate();
    spO2 = particleSensor.getSpO2();
    lcd.clear();
    lcd.print("Heart Rate: ");
    lcd.print(heartRate);
    lcd.setCursor(0, 1);
    lcd.print("SpO2: ");
    lcd.print(spO2);
    Blynk.virtualWrite(V0, heartRate);
    Blynk.virtualWrite(V1, spO2);
  }
  delay(1000);
}
