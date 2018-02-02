//reference: https://www.raywenderlich.com/32392/arduino-tutorial-for-complete-beginners-using-a-button
//this code uses the concept of a pull up resistor, which is already built into the arduino
//Here, if the switch is closed (like a button being pressed) then the switch pin is LOW
//the code with contact bounce for push buttons is here: https://www.arduino.cc/en/tutorial/switch

/*My three way switch is ordered accordingly:
 * 
 *  --------------------------
 * |  RUN   |  N/A   |  PRG   |     
 * |        |        |        |     
 * |   1    |   2    |   3    |     
 * |        |        |        |     
 *  --------------------------
 *     |        |        |
 *     |        |        |
 *     |        |        |
 *     
 *  Where RUN connects 1 and 2, PRG connects 1 and 3, and N/A connects neither leads   
 *     
 *     
 */

#define POT0 0 //on/off and brightness dial (analog pin #)
#define POT1 1 //R dial
#define POT2 2 //G dial
#define POT3 3 //B dial

#define MAXLEDS 18 



int switchInput1 = 1; //Digital pin of arduino that's connected to switch1
int switchInput2 = 2; //Digital pin of arduino that's connected to switch2

int switchState1 = 0; //switch states are either on or off (1 or 0)
int switchState2 = 0; //switch states are either on or off (1 or 0)
int oState = 0; //what overall state is the 3 way switch in? (1 = run; 2 = neither; 3 = Program)

int mode = 0; //what mode you want to run (mode 1 is default lamp mode)

void setup() {
  
    pinMode(switchInput1, INPUT);
    pinMode(switchInput2, INPUT);
    digitalWrite(switchInput1, HIGH); //write high (5v) to both switches 
    digitalWrite(switchInput2, HIGH);

}

void loop() {

  oState = CheckState();

  if (oState == 1){
    //Run

    if (mode == 1){
      //run default light code
    }

    
  }
  
  else if (oState == 3){
    //program mode
    //disable RGB dials
    //turn brightness dial to mode select
    //light up lights accordingly (lets say all red for now, might add a colour scheme later)

    mode = map(analogRead(POT0), 0 , 1023, 1 , 6); //maps POT0 (from A0) that's 0-1023, to a 1-6 range
    DisplayMode(mode);
    
  }

  else {
    //if oState == 2 (no clue what this will do yet)
  }

  

}

_____________________________________________________________________________________________________________________________________
//this checks the state of the 3 way switch (RUN/neither/PRG)
int CheckState (void){

    int State = 0;
    
    switchState1 = digitalRead(switchInput1);
    switchState2 = digitalRead(switchInput2);

    if (switchState1 == LOW) {
      //RUN mode
      State = 1;
      Serial.println("State: RUN");
    }

    else if (switchState2 == LOW) {
      //PRG mode
      State = 3;
      Serial.println("State: PRG");
    }

    else {
      //3 way switch is in the middle (N/A)
      State = 2;
      Serial.println("State: N/A");
    }

  return State;
  
}

_____________________________________________________________________________________________________________________________________
//this function displays the current mode by lighting up the corresponding number of LEDS

void DisplayMode (int mode){
  //note here we have 18 leds (0-17)
  //maybe add brightness later?

  int maxLeds = MAXLEDS - 1
  

  for (int led; led > (MAXLEDS - 1 + mode); led--){
    
    leds[led] = CRGB (0,0,255); //red
    //if led = maxleds + mode, then stop. if not, keep going 
    
  }
  
  FastLED.show();
  
}





_____________________________________________________________________________________________________________________________________
//problems to solve:
/*
 * EEPROM USE FOR RECALLING VARIBALES UPON POWER DOWN
 * https://arduino.stackexchange.com/questions/11941/how-to-remember-variable-values-after-rebooting-an-arduino-uno-r3-board
 * /
 */
