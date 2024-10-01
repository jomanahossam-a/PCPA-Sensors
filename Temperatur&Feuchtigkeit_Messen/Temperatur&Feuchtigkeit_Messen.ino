//autor:elif cansu yilmaz
//Sensoren:Feuchtigkeitssensor,Temperatursensor

//Werte für Temperatur
int TMP36 = A0; //Der Sensor soll am Analogen Pin A0 angeschlosen sein wir nennen ihn ab jetzt TMP36
int sensorwert;
int temperatur = 0; // unter der Variable Temparatur sollen wir später den TemparaturWert zurück kriegen hier soll er auch gespeichert werden
int t = 5000; // t soll uns die zeitliche Abstände zwischen zweier Abmessungen angeben
//Werte für Feuchtigkeit
int messwert = 0; //messwert der Feuchtigkeitssensor wird gemessen

void setup() {
  Serial.begin(9600);//Die kommunikation mit dem seriellen Monitor soll hier Aufgebaut werden damit uns die werte  zurück gegeben werden.
  //über die serielle kommunikation sendet das board die Messwerte an den Computer .WERKZEUGE/SERIELLER MONITOR starten um die Messwerte zu sehen

}

void loop() {
  //Temperatur
  sensorwert = analogRead(TMP36); //Auslesen des Sensorwertes
  temperatur = map(sensorwert, 0, 410, -50, 150); //map(umzuwandelnder Wert,Minimum Messbereich,Maximum Messbereich,Minimum Ausgabewert,Minimum Ausgabewert)=>der Befehl map
  //wandelt den Sensorwert
  delay(t);//nach jeder Messung wird eine Pause eingelegt hier in diesem Fall jede sekunde
  Serial.print(temperatur);//über die serielle kommunikation wird der wert"temperatur"an den PC gesendet.
  Serial.println("Grad Celsius");//Im seriellen Monitor wird die Einheit eingeblendet

  //Feuchtigkeit
  messwert = analogRead(A1);//Die Spannung an dem Sensor wird Ausgelesen und in variable "messwert" gespeichert
  Serial.print("Feuchtigkeits-Messwert:");//das wort Feuchtigkeitsmesswert wird ausgegeben
  Serial.println(messwert);//im Anschluss der eigentliche Wert
  delay(t);//zum Schluss kleine Paus der länge 5 sekunden

}
