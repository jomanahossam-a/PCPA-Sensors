int licht;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
 licht= analogRead(0);
 Serial.println(licht);

 if(licht > 130){
  digitalWrite(13,HIGH);
  
 }else{
  digitalWrite(13,LOW);
 }
}
