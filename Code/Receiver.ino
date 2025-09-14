#include <SoftwareSerial.h>

const int redPin = 4;
const int greenPin = 5;
const int buzzerPin = 6;

String data = "";

SoftwareSerial HC12(2,3);

void processData(String message)
{
	int percentIndex = message.indexOf("PERCENT:");
  	if (percentIndex == -1) {
    		Serial.println("DataNOTFound.");
    	return;
  	}
	String percentStr = message.substring(percentIndex + 8);
  	float pourcentage = percentStr.toFloat();

  	Serial.print("Pourcentage: ");
  	Serial.println(pourcentage);

  
  	if (pourcentage > 50.0) {
    		
    		digitalWrite(greenPin, HIGH);
    		digitalWrite(redPin, LOW);
    		digitalWrite(buzzerPin, LOW);
  	} else if (pourcentage <= 50.0 && pourcentage > 25.0) {
    		
    		digitalWrite(greenPin, LOW);
    		digitalWrite(redPin, HIGH);
    		digitalWrite(buzzerPin, LOW);
  	} else if (pourcentage <= 25.0) {
    		
    		digitalWrite(greenPin, LOW);
    		digitalWrite(redPin, HIGH);
    		digitalWrite(buzzerPin, HIGH);
  }
}

void setup()
{
	Serial.begin(9600);
	HC12.begin(9600);
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(buzzerPin, OUTPUT);
}

void loop()
{
	// Lecture d'une ligne complète depuis HC-12
  	while (HC12.available()) {
    		char c = HC12.read();
    		if (c == '\n') {
      		// treating received data
      		processData(data);
      		data = ""; // Reset 
    		} else {
      		data += c;
    		}
  	}
}
