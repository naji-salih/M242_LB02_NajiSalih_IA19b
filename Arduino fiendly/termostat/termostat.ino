//Following code was taken for inspiration to know how to use temparature measure: http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf


//Analog pin 0 used for temparature component
const int temperaturePin = A0;

//Digital pin 3 is used for the switch
const int pinOFswitch = 3;  

//Red, Green and Blue pins for the RGB Light
const int RED_PIN = 13;
const int GREEN_PIN = 11;
const int BLUE_PIN = 12;

// length of time each color is displayed
const int DISPLAY_TIME = 800; 

//Value State
int ValueOFswitch = 0;

void setup() {
	//Sset baud rate to 9600 bits per second (bps)
	Serial.begin(9600); 
  	
  	//Set Pins for Switch and RGB Light
  	pinMode(RED_PIN, OUTPUT);
  	pinMode(GREEN_PIN, OUTPUT);
  	pinMode(BLUE_PIN, OUTPUT);
  	pinMode(pinOFswitch, INPUT);  
}


void loop() {
  
  //Read out value of Switch
  ValueOFswitch = digitalRead(pinOFswitch);  
  
  //Check if Switch is ON
  if (ValueOFswitch == HIGH)   
  { 
    float voltage, degreesC;

    //Measure the voltage from the analog pin
	voltage = (analogRead(temperaturePin) * 0.004882814);

    // Convert the voltage to degrees Celsius
	degreesC = (voltage - 0.5) * 100.0; 

	//Print out the Degrees in the Serial Monitor
	Serial.print("  deg C: ");
	Serial.print(degreesC);
    
    //Set the right color for the Teparature
    //If it's cold the Light will be white (lower than 0 Degree Celcius)
    //If it's normal the light will be green (between 0 and 30 Degree Celcius)
    //If it's warm the light will be yellow (between 30 and 50 Degree Celcius)
    //If it's hot the Light will be red (between 50 and 100 Degree Celcius)
    //IF it's very hot the light will be violet! (<over 100 Degree Celcius)
    setColor(degreesC);
  } 
	
}


void setColor(int degreesC)
{
  
  if (degreesC <= 0){
    //Put RGB Light to White (turn all the LEDs on)
  	digitalWrite(RED_PIN, HIGH);
  	digitalWrite(GREEN_PIN, HIGH);
  	digitalWrite(BLUE_PIN, HIGH);
    //How long the light will be displayed
  	delay(DISPLAY_TIME);
    
  } else if (degreesC >= 0 && degreesC <= 30){
      //Put RGB Light to Green
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      delay(DISPLAY_TIME);
    
  } else if (degreesC > 30 && degreesC <= 50){
      //Put RGB Light to Yellow (Red and Green)
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      delay(DISPLAY_TIME);
    
  }else if (degreesC > 50 && degreesC <= 100){
    //Put RGB Light to Red
  	digitalWrite(RED_PIN, HIGH);
  	digitalWrite(GREEN_PIN, LOW);
  	digitalWrite(BLUE_PIN, LOW);
  	delay(DISPLAY_TIME);
  
  }else if (degreesC > 100){
    //Put RGB Light to Purple
  	digitalWrite(RED_PIN, HIGH);
  	digitalWrite(GREEN_PIN, LOW);
  	digitalWrite(BLUE_PIN, HIGH);
  	delay(DISPLAY_TIME);
  
  }
  
  // all LEDs off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(DISPLAY_TIME);  
}