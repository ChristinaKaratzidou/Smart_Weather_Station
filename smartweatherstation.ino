#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// ThingSpeak settings
unsigned long channelID = YOUR_CHANNEL_ID;
const char* apiKey = "YOUR_API_KEY";

// Sensor pins
#define DHTPIN 4          // DHT11 data pin
#define RAINPIN 34        // Rain sensor analog pin (use ADC pin)
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  // Initialize sensors
  dht.begin();
  pinMode(RAINPIN, INPUT);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  
  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Read rain sensor (0-4095 on ESP32)
  int rainValue = analogRead(RAINPIN);
  // Convert to percentage (inverse because sensor reads lower when wet)
  int rainPercentage = map(rainValue, 4095, 0, 0, 100);
  
  // Check if DHT reading was successful
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  Serial.print("Rain Level: ");
  Serial.print(rainPercentage);
  Serial.println("%");
  
  // Send data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, rainPercentage);
  
  int status = ThingSpeak.writeFields(channelID, apiKey);
  
  if(status == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Error sending data to ThingSpeak");
  }
  
  // Wait 15 seconds
  delay(15000);
}
