  
  
  // Master Arduino Code:
  #include<SPI.h>  // SPI-Bibliothek
  
  void setup () {
    SPI.begin();  // SPI-Initialisieren
    SPI.setClockDivider(SPI_CLOCK_DIV8);  // Clock für SPI Kommunikation auf 8 stellen (16/8=2Mhz)
    digitalWrite(SS,HIGH);  // Verbindung mit Slave stoppen
  }
  
  void loop()
  {
    uint16_t Mastersend,Mastereceive;          
    digitalWrite(SS, LOW);  // Verbindung zum Slave starten
    Mastereceive=SPI.transfer(Mastersend); // Mastersend Wert zu Slave schicken 
                                           // und gleichzeitig Masterreceive empfangen
    digitalWrite(SS, HIGH);
  
  
  // Slave Arduino Code:
  #include<SPI.h>
  
  volatile byte Slavereceived,Slavesend;
  
  void setup() {
    pinMode(MISO,OUTPUT);  // Aktivierung um Daten an Master zuschicken
    SPCR |= _BV(SPE);  // SPI auf Slave-Mode stellen
    SPI.attachInterrupt();  // Interrupt aktivieren
  }
  
  ISR (SPI_STC_vect) {  // SPI Interrupt Service Routine
                        // wird autom. aufgerufen wenn Master sendet
    Slavereceived = SPDR;  // Daten vom Master verarbeiten
    SPDR = Slavesend  // Daten dem Master zur Verfügung stellen
  }
