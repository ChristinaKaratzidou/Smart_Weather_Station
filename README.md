# Smart_Weather_Station
Smart Weather Station, an IoT based embedded project

Project Overview
The Smart Weather Station is an IoT-based embedded project that monitors and displays temperature, humidity, and rainfall in real time. Using the ESP32D microcontroller, the humidity-temperature sensor DHT11 and a rain drop sensor, this project offers a compact, efficient way for weather monitoring. ThingSpeak is used to log and visualize data in the cloud, enabling remote monitoring and analysis.

Features
Real-time temperature and humidity measurement using the DHT11 sensor
Rain detection with the raindrop sensor
Logs data to ThingSpeak for cloud-based storage and visualization

Components
ESP32-D: Microcontroller
DHT11 Sensor: Measures temperature and humidity
Raindrop Sensor: Detects rainfall
ThingSpeak: For cloud data storage and visualization
Jumper wires, breadboard, and micro usb cable

Hardware Connections
ESP32:
Connect the ESP32 to computer via the micro usb cable for power and programming.
DHT11 Sensor:
VCC: Connect to 3.3V on the ESP32.
GND: Connect to GND on the ESP32.
Data: Connect to GPIO 4 on the ESP32. DHT11 sensor communicates using a single-wire digital protocol, which requires a digital GPIO pin. GPIO 4 is a commonly used digital pin on the ESP32 and is suitable for this purpose.
Rain Sensor:
VCC: Connect to 3.3V on the ESP32.
GND: Connect to GND on the ESP32.
Analog Output: Connect to GPIO 34 on the ESP32. GPIO 34 is one of the ESP32's ADC (Analog-to-Digital Converter) pins, which can read analog voltages.

Software Setup
1) Install Arduino IDE
2) Add ESP32 Board
3) Install Required Libraries: DHT Sensor Library, ThingSpeak Library, ESP32 Wifi Library
4) Create ThingSpeak Channel: Field 1: Temperature, Field 2: Humidity, Field 3: Rain Level
