#include <SoftwareSerial.h>

int potPin = A0;
const int trigPin = 9;
const int echoPin = 10;
float duration, level_of_water;
SoftwareSerial HC12(2,3);

void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
	HC12.begin(9600);
}

void loop()
{
  	digitalWrite(trigPin, LOW);
  	delayMicroseconds(2);
 	  digitalWrite(trigPin, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin, LOW);

	int rawValue= analogRead(potPin);
	float height=map(rawValue,0,1023,0,600);

	duration=pulseIn(echoPin, HIGH);
	level_of_water=(duration*0.0343)/2;

	if (level_of_water < 0 || level_of_water > 600) 
		{
    			Serial.println("Unexistent Value");
    			return;
  		}

	float pourcentage =((height - level_of_water) / height) * 100.0;
  	HC12.print("WATER_LEVEL:");
  	HC12.print(level_of_water,1);
  	HC12.print(";");
  	HC12.print("PERCENT:");
  	HC12.println(pourcentage,1);

	delay(2000); //CHANGE LATER TO 60 SECONDS.
	
}

