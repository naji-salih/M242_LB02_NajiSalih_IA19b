//Code-snippeds inspired from:
//To hide password with * on Display https://www.arduinoplatform.com/keypads-and-displays/reading-a-4-x-4-keypad-with-arduino/

// Load the LiquidCrystal and Keypas libraries, which will give us commands use
#include <LiquidCrystal.h>
#include <Keypad.h>

// Define LCD display pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


// Number in Rows and Cols
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

//Define where the pins are for the rows
byte rowPins[KEYPAD_ROWS] = { 7, 6, 5, 4 }; 

//Define where the pins are for the cols
byte colPins[KEYPAD_COLS] = { 3, 2, A0, A1 };

//Define the keys on the keypad
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Declare keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);


void setup()
{
  Serial.begin(9600);
  
  //Set pins for each pin of the rows as input
  for (int row = 0; row < KEYPAD_ROWS; row++) { 
    
    pinMode(rowPins[row], INPUT); 
    
    // turn on Pull-ups
    digitalWrite(rowPins[row], HIGH); 
  }
  
  //Set pins for each pin of the cols as input
  for (int column = 0; column < KEYPAD_COLS; column++) {
    
    pinMode(colPins[column], OUTPUT); 
    
  	// Make all columns inactive
    digitalWrite(colPins[column], HIGH); 
  
  	//Initialize the 16x2 LCD
	lcd.begin(16, 2); 

	//Clear any data displayed on the LCD
	lcd.clear();		
  }
}

void loop() {  
  
  //Print the inital message to enter password
  lcd.print("Type in password");
  lcd.setCursor(5, 1);
  lcd.print("[____]");
  lcd.setCursor(6, 1);
  String result = "";
  
  //Let the user type in a 4 digit password
  while (result.length() < 4) {
    char key = keypad.getKey();
    
    //Only numbers are allowed to type in
    if (key >= '0' && key <= '9') {
      lcd.print('*');
      result += key;
    }
  }
  delay(10);
  
  //Print the typed in password in serial monitor
  Serial.print("Password typed: ");
  Serial.println(result);
  
  //Check if the Password is correct
  //If password is correct print out correct in LCD display
  if(result=="4488"){
    //clear all messages on display
    lcd.clear();
    //set cursor to write on frist row
    lcd.setCursor(5, 0);
	lcd.print("correct!"); 
	delay(3000);
    lcd.clear();  
  }else{
    //If password is wrong print out response on LCD display
  	lcd.clear();
    //set cursor to write on frist row
    lcd.setCursor(5, 0);
	lcd.print("Wrong!");
    //set cursor to write on second row
    lcd.setCursor(2, 1);
	lcd.print("Try again!"); 
	delay(3000);
    lcd.clear();  
  }
}
