# DIR-V-SUBMISSION
# 🩺 BIST-Enabled Health Monitoring System 🚀

🏆 National-Level Hackathon Project
This project implements a "self-diagnostic IoT health monitoring system" using:
- VSD Squadron Mini RISC-V Board
- MAX30102 Heart Rate & SpO₂ Sensor
- ESP8266 Wi-Fi Module
- LCD Display & Blynk Mobile App
- **Built-In Self-Test (BIST) for Fault Detection**



## 📌 **Project Overview**
The system continuously monitors **heart rate and SpO₂ levels** and detects **sensor faults** in real-time.  
It consists of three key operations:

1️⃣ **Functional Integrity Test** – Ensures the sensor responds correctly to input stimuli.  
2️⃣ **Signal Integrity & Noise Test** – Injects noise to test signal stability under real-world conditions.  
3️⃣ **Diagnostic Register & Internal Error Test** – Simulates internal sensor faults and verifies error detection.  

All outputs are displayed on **LCD** and sent to the **Blynk mobile app via Wi-Fi**.



## 🔧 **Hardware Setup & Connections**
### **Components Used**
- ✅ **VSD Squadron Mini RISC-V Board** – Microcontroller to process data & run BIST
- ✅ **MAX30102 Pulse Oximeter Sensor** – Measures Heart Rate & SpO₂
- ✅ **ESP8266 Wi-Fi Module** – Sends data to the Blynk mobile app
- ✅ **LCD Display (I2C)** – Displays sensor readings and fault alerts

### **Wiring Diagram**
| Component  | VSD Squadron Mini Pin | MAX30102 / ESP8266 Pin |
|------------|---------------------- |------------------------|
| MAX30102 VCC|         3.3V         | Power Supply |
| MAX30102 GND |          GND | Ground |
| MAX30102 SDA | GPIO0 (SDA) | I2C Data |
| MAX30102 SCL | GPIO1 (SCL) | I2C Clock |
| ESP8266 TX | RX | Serial Data |
| ESP8266 RX | TX | Serial Data |
| LCD VCC | 3.3V | Power Supply |
| LCD SDA | GPIO2 | I2C Data |
| LCD SCL | GPIO3 | I2C Clock |

📜 **Circuit Diagram:** [View Here](hardware/schematic.png)

---

## 🔑 **How It Works**
📌 **Step 1:** VSD Squadron Mini RISC-V board initializes MAX30102 and performs BIST.  
📌 **Step 2:** Data is read, and faults (if any) are detected.  
📌 **Step 3:** Processed data is displayed on **LCD** and sent via **ESP8266** to Blynk.  

📸 **Live Output:**  
![LCD Display](images/lcd_output.jpg)  
📱 **Blynk App UI:**  
![Blynk UI](images/blynk_interface.png)  

---

## 🖥 **Code Structure & Testing**
- **`code/functional_test.ino`** → Ensures the sensor produces valid heart rate & SpO₂ data.
- **`code/noise_test.ino`** → Injects noise to test signal reliability.
- **`code/diagnostic_test.ino`** → Simulates internal faults via error registers.

📜 **Code Files:** [View Here](code/)

### 🛠 **Testing & Fault Injection**
✔ **Case 1: Normal Operation** – Displays valid heart rate & SpO₂.  
❌ **Case 2: Injected Noise** – Adds random fluctuations in sensor data.  
❌ **Case 3: Internal Fault Simulation** – Simulates ADC overflow & LED driver errors.

📜 **Fault Logs & Results:** [View Here](tests/bist_test_results.txt)

---

## 📲 **Blynk Mobile App Setup**
- Install **Blynk** from Play Store/App Store.
- Create a new project and add **Value Display Widgets** for **HR & SpO₂**.
- Connect **ESP8266 via Wi-Fi** and input the provided **Auth Token**.

📜 **Setup Guide:** [View Here](docs/setup_guide.md)

---

## ⚡ **How to Run the Project**
```sh
# Clone the Repository
git clone https://github.com/your-username/BIST-Enabled-Health-Monitor.git

# Open in Arduino IDE / PlatformIO
# Select the correct board & upload the code
```

---

## 📜 **License**
This project is licensed under the **MIT License**. Feel free to modify and improve it! 🚀

---

## 🤝 **Contributors**
- **Jhanavi M** *(Project Lead)*
- **Dhruva R*
- **Special Thanks to Open-Source Libraries & VSD Community*


