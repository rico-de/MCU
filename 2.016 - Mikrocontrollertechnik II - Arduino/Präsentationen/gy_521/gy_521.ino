  #include<Wire.h>  // I²C-Bibliothek
  const int MPU=0x68;  // I²C-Adresse  des MPU-6050 
  int16_t GyX,GyY,GyZ;  // Variablen für Daten
  
  void setup() {
    Wire.begin();  // I²C initialisieren
    Wire.beginTransmission(MPU);  // Verbindung mit Slave MPU
    Wire.write(0x6B);  // MPU mit Spannung versorgen 
    Wire.write(0);  // MPU-Aufwecken
    Wire.endTransmission(true);  // Verbindung beenden
  }
  void loop() {
    Wire.beginTransmission(MPU);
    Wire.write(0x43);  // Anfrage für Gyroregister stellen  
    Wire.endTransmission(false);
    Wire.requestFrom(MPU,6,true);  // 6 Register einlesen
    GyX=Wire.read()<<8|Wire.read();  // High-Byte und Low-Byte in lesen
    GyY=Wire.read()<<8|Wire.read();  
    GyZ=Wire.read()<<8|Wire.read(); 
