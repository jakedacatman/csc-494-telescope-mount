include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "";
const char* password = "";

// Web server on port 80
WebServer server(80);

// Serial pins for ESP32C6
#define RXD2 17  // Connect to Arduino TX via level shifter
#define TXD2 16  // Connect to Arduino RX via level shifter

void setup() {
  // Serial for debugging
  Serial.begin(115200);
  
  // Serial for Arduino communication
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  
  Serial.println("\nESP32C6 Web Server");
  Serial.println("=========================");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Setup web server routes
  server.on("/", HTTP_POST, handleData);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle web server requests
  server.handleClient();
}

// JSON data endpoint
void handleData() {
  String s = server.arg("steps");
  if (!s.toInt()) s = "0";
  Serial1.println(s);
  while (!Serial1.available()) {}
  
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", Serial1.readStringUntil('\n'));
}
