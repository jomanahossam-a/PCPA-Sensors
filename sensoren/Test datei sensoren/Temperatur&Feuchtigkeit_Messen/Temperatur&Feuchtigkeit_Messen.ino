//Sensoren:Feuchtigkeitssensor,Temperatursensor, 9DOF
#include "ICM20600.h"
#include <Wire.h>

//Werte für Temperatur
int TMP36 = A0; //Der Sensor soll am Analogen Pin A0 angeschlosen sein wir nennen ihn ab jetzt TMP36
int sensorwert;
int temperatur = 0; // unter der Variable Temparatur sollen wir später den TemparaturWert zurück kriegen hier soll er auch gespeichert werden
int t = 5000; // t soll uns die zeitliche Abstände zwischen zweier Abmessungen angeben
//Werte für Feuchtigkeit
int messwert = 0; //messwert der Feuchtigkeitssensor wird gemessen
int acc_x, acc_y, acc_z;
int gyr_x, gyr_y, gyr_z;
//Für 9OF
ICM20600 icm20600(true);





void setup() {
  Wire.begin();
  Serial.begin(9600);//Die kommunikation mit dem seriellen Monitor soll hier Aufgebaut werden damit uns die werte  zurück gegeben werden.
  //über die serielle kommunikation sendet das board die Messwerte an den Computer .WERKZEUGE/SERIELLER MONITOR starten um die Messwerte zu sehen
  icm20600.initialize();

}

void loop() {
  //Temperatur
  sensorwert = analogRead(TMP36); //Auslesen des Sensorwertes
  temperatur = map(sensorwert, 0, 410, -50, 150); //map(umzuwandelnder Wert,Minimum Messbereich,Maximum Messbereich,Minimum Ausgabewert,Minimum Ausgabewert)=>der Befehl map
  //wandelt den Sensorwert
  Serial.print("Temperatur-Messwert: ");
  Serial.println(temperatur);
  Serial.println("Grad Celsius");//Im seriellen Monitor wird die Einheit eingeblendet
  delay(t);//nach jeder Messung wird eine Pause eingelegt hier in diesem Fall jede sekunde

  //Feuchtigkeit
  messwert = analogRead(A1);//Die Spannung an dem Sensor wird Ausgelesen und in variable "messwert" gespeichert
  Serial.print("Feuchtigkeits-Messwert:");//das wort Feuchtigkeitsmesswert wird ausgegeben
  Serial.println(messwert);//im Anschluss der eigentliche Wert
  delay(t);//zum Schluss kleine Paus der länge 5 sekunden

  //Drehbewegung: Gyroskop in dps (degree per second)
  Serial.print("Drehbewegungen-Messwert:");
  gyr_x=icm20600.getGyroscopeX();
  gyr_y=icm20600.getGyroscopeY();
  gyr_z=icm20600.getGyroscopeZ();
  Serial.print("X=");
  Serial.print(gyr_x);
  Serial.print(",  ");
  Serial.print("Y=");
  Serial.print(gyr_y);
  Serial.print(",  ");
  Serial.print("Z=");
  Serial.print(gyr_z);
  Serial.println(" dps");
  delay(t);

  //Beschleunigung: Accelometer in mg (g-force)
  Serial.print("Beschleunigung-Messwert:");
  acc_x = icm20600.getAccelerationX();
  acc_y = icm20600.getAccelerationY();
  acc_z = icm20600.getAccelerationZ();

  Serial.print("X=");
  Serial.print(acc_x);
  Serial.print(",  ");
  Serial.print("Y=");
  Serial.print(acc_y);
   Serial.print(",  ");
  Serial.print("Z=");
  Serial.print(acc_z);
  Serial.println(" mg");
  delay(t);

}
