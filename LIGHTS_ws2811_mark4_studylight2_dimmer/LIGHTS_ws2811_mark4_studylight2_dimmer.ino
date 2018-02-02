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

  //fill_solid(leds, NUM_LEDS, CRGB::Black); 
  
  leds[0] = CRGB (blue, green, red);
  leds[1] = CRGB (blue, green, red);
  leds[2] = CRGB (blue, green, red);
  leds[3] = CRGB (blue, green, red);
  leds[4] = CRGB (blue, green, red);



  FastLED.setBrightness(100);
  CBright = DimBy();
  leds[0] %= CBright;
  leds[1] %= CBright;
  leds[2] %= CBright;
  leds[3] %= CBright;
  leds[4] %= CBright;

  FastLED.show();

}
  


int DimBy (void)
{
  int brightness = analogRead(1); //reads A1
  Serial.println(brightness);
  brightness = map(brightness, 0, 1023, 0, 255);
  Serial.println(brightness);
  //delay (100);
  return brightness; 
  
}


