// C++ code
//

const int switchPin = 13;
//Value State
int ValueOFswitch = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
  
   pinMode(switchPin, INPUT);


//Start all ligts and turn them off to see if all lights are working.  
    allOn();
  	delay(1500);
    allOff();
  	delay(200);
}


void loop()
{ 
ValueOFswitch = digitalRead(switchPin); 
//Check if Switch is ON
  if (ValueOFswitch == HIGH)   
  { 
    lightShowOne();
    lightShowTwo();
    lightShowThree();
  }
}



//Here you can find my firat Lightshow whitch flows thrue the lights one by one.
void lightShowOne(){   
 for (int i = 2; i <=11; i++){
  	digitalWrite(i, HIGH);
   	delay(200);
    digitalWrite(i, LOW);
   	delay(200);
  }
}


//Here is my second lightshow which takes the light as color pairs two at the time.
void lightShowTwo(){   
 for (int i = 2; i <11; i +=2){
  	digitalWrite(i, HIGH);
   	digitalWrite(i + 1, HIGH);
    delay(200);
  
  	digitalWrite(i, LOW);
   	digitalWrite(i + 1, LOW);
    delay(200);
  }
}

//This is the shuffle effect where it turns every second light onand rewerse it after.
void lightShowThree(){   
 for (int i = 2; i <=11; i++){
   digitalWrite(2, HIGH); 
   digitalWrite(3, LOW); 
   digitalWrite(4, HIGH); 
   digitalWrite(5, LOW); 
   digitalWrite(6, HIGH); 
   digitalWrite(7, LOW); 
   digitalWrite(8, HIGH); 
   digitalWrite(9, LOW); 
   digitalWrite(10, HIGH); 
   digitalWrite(11, LOW); 
   delay(150); 
   
   digitalWrite(2, LOW); 
   digitalWrite(3, HIGH); 
   digitalWrite(4, LOW); 
   digitalWrite(5, HIGH); 
   digitalWrite(6, LOW); 
   digitalWrite(7, HIGH); 
   digitalWrite(8, LOW); 
   digitalWrite(9, HIGH); 
   digitalWrite(10, LOW); 
   digitalWrite(11, HIGH); 
   delay(150);
  }
	allOff();
}

//mehtod all On to trun all the lights on
void allOn(){   
 for (int i = 2; i <=11; i++){
  	digitalWrite(i, HIGH);
    
  }
}

//mehtod all Off to trun all the lights Off
void allOff(){   
 for (int i = 2; i <=11; i++){
  	digitalWrite(i, LOW);
    
  }
}


