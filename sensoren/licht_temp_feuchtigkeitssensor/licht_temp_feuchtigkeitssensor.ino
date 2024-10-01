//Sensoren:Feuchtigkeitssensor,Temperatursensor,Lichtsensor

//Werte für Temperatur
 //Der Sensor soll am Analogen Pin A0 angeschlosen sein wir nennen ihn ab jetzt TMP36
int sensorwert;
int Temperatur = 0; // unter der Variable Temparatur sollen wir später den TemparaturWert zurück kriegen hier soll er auch gespeichert werden

//Werte für Feuchtigkeit
int Messwert = 0; //messwert der Feuchtigkeitssensor wird gemessen
//Werte für licht sensor
int Lichtwert = 0;

void setup() {
  Serial.begin(9600);//Die kommunikation mit dem seriellen Monitor soll hier Aufgebaut werden damit uns die werte  zurück gegeben werden.
  //über die serielle kommunikation sendet das board die Messwerte an den Computer .WERKZEUGE/SERIELLER MONITOR starten um die Messwerte zu sehen

}

void loop() {
  delay(5000);
  //TEMPERATUR
  sensorwert = analogRead(A0); //Auslesen des Sensorwertes
  Temperatur = map(sensorwert, 0, 410, -50, 150); //map(umzuwandelnder Wert,Minimum Messbereich,Maximum Messbereich,Minimum Ausgabewert,Minimum Ausgabewert)=>der Befehl map
  //wandelt den Sensorwert
  delay(6000);
  Serial.print("Temperatur-Wert:");//über die serielle kommunikation wird der wert"temperatur"an den PC gesendet.
  Serial.println(Temperatur);//Im seriellen Monitor wird die Einheit eingeblendet
  
  
  

  
  //FEUCHTIGKEIT
  Messwert = analogRead(A1);//Die Spannung an dem Sensor wird Ausgelesen und in variable "messwert" gespeichert
  delay(6000);
  Serial.print("Feuchtigkeits-Messwert:");//das wort Feuchtigkeitsmesswert wird ausgegeben
  Serial.println(Messwert);//im Anschluss der eigentliche Wert
  
  

  
  
  //LICHT
  Lichtwert= analogRead(A2);
  delay(6000);
  Serial.print("Lichtwert: ");
  Serial.println(Lichtwert);   // 
  
  

  

  
}
