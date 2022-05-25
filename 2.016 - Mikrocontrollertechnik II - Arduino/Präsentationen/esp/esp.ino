#include <ESP8266WiFi.h>

const char* ssid = "your SSID"; 
const char* password = "your PASSWORD";

WiFiServer server(80);  // Server Objekt für Port 80 erzeugen

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);	// Wifi Verbindung herstellen
  while (WiFi.status() != WL_CONNECTED) {  // Warten bis Connected
    delay(500);
    Serial.print(".");    
  }
  server.begin();  // Server starten
  Serial.print("Wifi connected IP: ");
  Serial.println(WiFi.localIP());  // NodeMCU IP-Adresse ausgeben
}

void loop() {
  WiFiClient client = server.available();  // Bei Verbindungsanfrage Client erzeugen
  if (client) {  
    while (client.connected()) {  // 
      if (client.available()) {  // bei TCP Anfrage, dem Client mit HTML antworten
        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("MY HTML CODE");
        client.println("</html>");
        break;
      }
    }
  }
  delay(1000);
  client.stop();  // Verbindung zum Client trennen
}
