//Code sniped used to know how to use vibrator: //https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/

//Define pin for gas sensor
int GasSensor = A5;
//Define pin for piezo
int piezoPin = 8;
//Define pin for vibrator motor
int motorPin = 3;
//Define pin for red light
int redLight = 9;
//Define pin for switch
int pinOFswitch = 4;  


//Define pins for RGB Light
const int RED_PIN = 12;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

int LimitThreshHold = 60;

//Value for reading switch state
int ValueOFswitch = 0;


void setup()
{
  	//Set all pins
  	pinMode(RED_PIN, OUTPUT);
  	pinMode(GREEN_PIN, OUTPUT);
  	pinMode(BLUE_PIN, OUTPUT);
	pinMode(GasSensor,INPUT);
    pinMode(motorPin, OUTPUT);
    pinMode(pinOFswitch, INPUT);  
    pinMode(redLight, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
  
  //Read value of Switch
  ValueOFswitch = digitalRead(pinOFswitch);  
  
  // check if the Switch is ON.
  if (ValueOFswitch == HIGH){
    //If Switch is on, lught Red light to inidcate that Gas Alarm is on and working
    digitalWrite(redLight, HIGH); 

    //Read Gas-Sensor value
    int analogValue = analogRead(GasSensor);;

    //prints the value of Gas Sensor in the Serial Monitor
    Serial.println(analogValue);

    //If the distance the gas is over the thresHold, put on Alarm (but still under 100)
    if(analogValue>LimitThreshHold && analogValue<=100)
    {
      
      //Let the Piezo ring the alarm tone
      tone(8, 1500, 10);
      
      //Vibrate for Blind and Deaf People
      digitalWrite(motorPin, HIGH); //vibrate

      // Let the RGB Light turn Yellow to inicate that there is Gas
    	digitalWrite(RED_PIN, HIGH);
    	digitalWrite(GREEN_PIN, HIGH);
    	digitalWrite(BLUE_PIN, LOW);
    
      //If the Gas distance value is over 100 (Very close and a lot)
    }else if(analogValue>100){
      	//Let the Piezo ring the alarm tone
      	tone(8, 1500, 10);
      	//Vibrate for Blind and Deaf People
      	digitalWrite(motorPin, HIGH);
        // Let the RGB Light turn RED to inicate that there is Gas very close and a lot
    	digitalWrite(RED_PIN, HIGH);
    	digitalWrite(GREEN_PIN, LOW);
    	digitalWrite(BLUE_PIN, LOW);
    }else {
    	digitalWrite(motorPin, LOW); 
    	// Turn off all RGB Lights
    	digitalWrite(RED_PIN, LOW);
    	digitalWrite(GREEN_PIN, LOW);
    	digitalWrite(BLUE_PIN, LOW);
    } 
  }
    //When the Switch is off everything off
    else
    {
      	// Turn off the Red LED to indicate that the Alarm is OFF
    	digitalWrite(redLight, LOW);
      	digitalWrite(motorPin, LOW); 

    } 
     
}