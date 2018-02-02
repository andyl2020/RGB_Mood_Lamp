#include "FastLED.h"

#define LED_TYPE    WS2811
#define LED_PIN     7
#define NUM_LEDS    20
#define BRIGHTNESS  64

#define COLOR_ORDER RBG

//default: GRB results in RBG(tested)
//we want: blue/green/red (so type RBG) -> IT WORKS!!! CRGB (blue, green red)

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);   
  delay(1000);

  FastLED.setBrightness(50);
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

   
  int red = 0;
  int green = 255;
  int blue = 0;

  //fill_solid(leds, NUM_LEDS, CRGB::Black); 
  
  leds[0] = CRGB (blue, green, red);
  leds[1] = CRGB (blue, green, red);
  leds[2] = CRGB (blue, green, red);
  leds[3] = CRGB (blue, green, red);
  leds[4] = CRGB (blue, green, red); 

  //fill_solid(leds, NUM_LEDS, CRGB::Black); 
  
  int newRed = analogRead(5); //reads A1
  Serial.print("RED1  : ");
  Serial.print(newRed);
  Serial.print(" RED2  : ");
  newRed = map(newRed, 0, 1023, 0, 255);
  Serial.println(newRed);
  //delay (100);
  //note that increments happen AFTER the statement is executed 



  //note that increments happen AFTER the statement is executed 
  for (int y=0; y < 5 ; y++){ 
    //works up til ledArray[4]
    leds[y] = CRGB (0, newRed, 0);
  }
  FastLED.show();
  
  delay(500);
}
  




