/*
Lo que hace este código:
1) LED parapades (Pin 13) con el pulso del usuario
2) En seguida otro LED (Pin 5) se desvanece
3) Determina los LPM
4) Imprime todo en el monitor Serial

*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

byte corazon[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

//  Variables
int pulsePin = 0;                 // INPUT (Sensor de pulso)
int blinkPin = 13;                // Pin que parpadea
int fadePin = 6;                  // Pin que se desvanece
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin              ////////////////
const int buzzer = 8; 

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual =true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 


void setup(){
  
  lcd.begin(16, 2);
  lcd.print("Ritmo Cardiaco: ");
  lcd.createChar(0, corazon);


  
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);   
 
}


//  Where the Magic Happens
void loop(){  

  Serial.println(analogRead(A0));
    // wait a bit for the analog-to-digital converter
    // to stabilize after the last reading:
    delay(2);
    serialOutput() ;       
    
  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        fadeRate = 255;         // Makes the LED Fade Effect Happen
                              // Set 'fadeRate' Variable to 255 to fade LED with pulse
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time    
  }
     
  ledFadeToBeat();                      // Makes the LED Fade Effect Happen 
  
  delay(20);                             //  take a break

}





void ledFadeToBeat(){
    fadeRate -= 15;                         //  set LED fade value
    fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
    analogWrite(fadePin,fadeRate);          //  fade LED
    analogWrite(blinkPin,fadeRate); 
    
  }




