#include "FastLED.h"


#define LED_TYPE    WS2812
#define LED_PIN     7
#define NUM_LEDS    8
#define BRIGHTNESS  64

#define COLOR_ORDER RBG

//default: GRB results in RBG(tested)
//we want: blue/green/red (so type RBG) -> IT WORKS!!! CRGB (blue, green red)

CRGB leds[NUM_LEDS];

void setup()
{
  //FastLED.addLeds<WS2812,DATA_PIN>(leds, NUM_LEDS); //libary.used <specific branch in library, data pin used> (where array is found, # leds)
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600); 
  FastLED.clear();  
}

/*// This function prints the Analog pin value to the serial console
// For debugging only, not necessary for the strand to light
void PinDebug(int AnalogVal)
{
  Serial.println(AnalogVal);
  delay(100);
}*/


// This loop reads the value of Analog Pin 1 into (aRead), then calls one of three functions (WS2812_Low, WS2812_Mid, or WS2812_High) depending on that value
// If it calls WS2812_Mid, it also passes the (aRead) value which is used to determine which lights should be lit in the strand
void loop()
{  //ORDER IS: CRGB (blue, green, red)

  int red=255;
  int green=0;
  int blue=0;
  
  while (1)
  {
    
  

  /*leds[0] = CRGB (200,0,0);
  leds[1] = CRGB (0,200,0);
  leds[2] = CRGB (0,0,200);
  leds[3] = CRGB (0,255,255);*/
  leds[4] = CRGB (blue, green, red);
  leds[5] = CRGB (blue, green, red);
  leds[6] = CRGB (blue, green, red);
  leds[7] = CRGB (blue, green, red);
  leds[8] = CRGB (blue, green, red);
  leds[9] = CRGB (blue, green, red);

  if (green >= 255)
  {
    red = 0;
    blue += 5;  

  }

  else
  {
    green += 5;
  }

  FastLED.setBrightness(70);
  FastLED.show();
  Serial.print(red);
  Serial.print("\t");
  Serial.println(green);
  Serial.print("\t");
  Serial.println(blue);
  FastLED.clear();
  delay(200);
  }
  

/*while (1)
{
  colour++;
  FastLED.clear();
  leds[0] = colour; //blue
  

  FastLED.setBrightness(30);
  FastLED.show();
  Serial.println(colour);
  delay(500);



}*/
  /*while (colour > 0xFFFFFF)
  {
    colour = colour + 0x0000F0;
    leds[0] = color;
    FastLED.setBrightness(30);
    FastLED.show();
    delay(500);
  }*/






}




