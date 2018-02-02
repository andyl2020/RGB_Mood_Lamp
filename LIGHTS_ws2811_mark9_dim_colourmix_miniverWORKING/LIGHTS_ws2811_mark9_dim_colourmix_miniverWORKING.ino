#include "FastLED.h"

#define LED_TYPE    WS2811
#define LED_PIN     5
#define NUM_LEDS    18
#define BRIGHTNESS  64

#define COLOR_ORDER RBG

//default: GRB results in RBG(tested)
//we want: blue/green/red (so type RBG) -> IT WORKS!!! CRGB (blue, green red)

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);   
  delay(1000); //safety delay

  FastLED.setBrightness(100);
  set_max_power_in_volts_and_milliamps(12, 700); 

  
}

//prints whatever is on analog pin
void PinDebug (int AnalogPin)
{
  Serial.println(AnalogPin);
  delay(100);
}



void loop()
{ 
   //ORDER IS: CRGB (blue, green, red)

   
  int red;
  int green;
  int blue;

  //fill_solid(leds, NUM_LEDS, CRGB::Black); 

  
  int newRed = analogRead(1); //reads A1
  Serial.print("RED1  : ");
  Serial.print(newRed);
  Serial.print(" RED2  : ");
  newRed = map(newRed, 0, 1023, 0, 255); //maps newRed (from A1) that's 0-1023, to a 0-255 range
  Serial.println(newRed);
  //delay (100);
  //note that increments happen AFTER the statement is executed 



  int newGreen = analogRead(2); //reads A1
  Serial.print("GREEN1: ");
  Serial.print(newGreen);
  Serial.print(" GREEN2: ");
  newGreen = map(newGreen, 0, 1023, 0, 255);
  Serial.println(newGreen);

  

  int newBlue = analogRead(3); //reads A1
  Serial.print("BLUE1 : ");
  Serial.print(newBlue);
  Serial.print(" BLUE2 : ");
  newBlue = map(newBlue, 0, 1023, 0, 255);
  Serial.println(newBlue);


  
  //note that increments happen AFTER the statement is executed 
  //fills up all leds with appropiate colours 
  for (int y=0; y < NUM_LEDS ; y++){ 
    //works up til ledArray[4]
    leds[y] = CRGB (newBlue,newGreen,newRed);
    leds[y] %= DimBy();
  }
  FastLED.show();
  
  //delay(500);
}
  

int DimBy (void)
{
  int brightness = analogRead(0); //reads A1
  Serial.println(brightness);
  brightness = map(brightness, 0, 1023, 0, 255);
  Serial.println(brightness);
  //delay (100);
  return brightness; 
  
}


