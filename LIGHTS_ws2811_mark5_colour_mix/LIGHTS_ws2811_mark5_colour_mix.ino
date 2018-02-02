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
{  //ORDER IS: CRGB (blue, green, red)

  int red = 255;
  int green = 0;
  int blue = 0;
  int CBright = 0;

  fill_solid(leds, NUM_LEDS, CRGB::Black); 
  
  leds[0] = CRGB (0,0,255);
  leds[1] = CRGB (0,175,255);
  leds[2] = CRGB (0,255,255);
  leds[3] = CRGB (0,255,175);
  leds[4] = CRGB (0,255,0);
  leds[5] = CRGB (175,255,0);
  leds[6] = CRGB (255,255,0);
  leds[7] = CRGB (255,175,0);
  leds[8] = CRGB (255,0,0);
  leds[9] = CRGB (255,0,175);
  leds[10] = CRGB (255,0,255);
  leds[11] = CRGB (175,0,255);
  leds[12] = CRGB (0,0,255);
  leds[13] = CRGB (200,100,250);
  leds[14] = CRGB (99, 177, 80);
  



  FastLED.setBrightness(30);
  FastLED.show();

}
  





