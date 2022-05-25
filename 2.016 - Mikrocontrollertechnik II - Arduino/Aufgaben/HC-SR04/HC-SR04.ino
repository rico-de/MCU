int trigPin =2 ; 
int echoPin =3 ;  
float duration_us, distance_cm;

void setup() {
  pinMode(trigPin, OUTPUT); // Trigger-Pin als OUTPUT konfigurieren
  pinMode(echoPin, INPUT);  // Echo-Pin als INPUT konfigurieren
}

void loop() {
  // 10µs Impuls über den Trigger-Pin schicken
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Zeitmessung bis Signal zurück kommt
  duration_us = pulseIn(echoPin, HIGH);

  // Berechnung der Distanz in cm
  distance_cm = 0.017 * duration_us;
}
