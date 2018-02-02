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

int switchInput1 = 7; //Digital pin of arduino that's connected to switch1
int switchInput2 = 9; //Digital pin of arduino that's connected to switch2

int switchState1 = 0; //switch states are either on or off (1 or 0)
int switchState2 = 0; //switch states are either on or off (1 or 0)
int oState = 0; //what overall state is the 3 way switch in? (1 = run; 2 = neither; 3 = Program)


void setup() {

    Serial.begin(9600);
    pinMode(switchInput1, INPUT);
    pinMode(switchInput2, INPUT);
    digitalWrite(switchInput1, HIGH); //write high (5v) to both switches 
    digitalWrite(switchInput2, HIGH);
    Serial.println("working");

}

void loop() {
    switchState1 = digitalRead(switchInput1);
    switchState2 = digitalRead(switchInput2);

    if (switchState1 == LOW) {
      //RUN mode
      oState = 1;
      Serial.println("State: RUN");
    }

    else if (switchState2 == LOW) {
      //PRG mode
      oState = 3;
      Serial.println("State: PRG");
    }

    else {
      //3 way switch is in the middle (N/A)
      oState = 2;
      Serial.println("State: N/A");
    }

}


int checkState (void){



  
}



