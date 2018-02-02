// Basic Piece #1
// This is the library that we're using to adress our WS2812 LEDs
#include "FastLED.h"

// Basic Piece #2
// How many LEDs will you have in your array?
#define NUM_LEDS 8

// Basic Piece #3
// We'll be using Digital Data Pin #7 on the Arduino to control the WS2812
#define DATA_PIN 7

//Basic Piece #4
// Creates an array with the length set by NUM_LEDS above
// This is the array the library will read to determine how each LED in the strand should be set
CRGB leds[NUM_LEDS];

// Basic Piece #5
// This tells the library that there is a strand of NEOPIXELS attached to the Arduino
// that they are connected to the DATA_PIN specified above
// that the library should look at the array called "leds"
// and that there are the number of LEDs in the strand as defined above in "NUM_LEDS" 
// It also opens the serial port for the PinDebug() function
void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}

// This function prints the Analog pin value to the serial console
// For debugging only, not necessary for the strand to light
void PinDebug(int AnalogVal)
{
  Serial.println(AnalogVal);
  delay(100);
}

// This function is called if the value of (aRead) is 0-49
// I first clear the values of the LEDs in the strand, then I fill the array with color values, then set brightness, then pushed the values to the strand with "FastLED.show();"
// It would be REALLY easy to replace the manual setting of each array value with a loop. Why not try it?
void WS2812_Low()
{
  FastLED.clear();
  leds[0] = CRGB::Yellow;
  leds[1] = CRGB::Yellow;
  leds[2] = CRGB::Yellow;
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;
  leds[6] = CRGB::Yellow;
  leds[7] = CRGB::Yellow; 
  
  FastLED.setBrightness(30);
  FastLED.show();
}

// This function is called if the value of (aRead) is 50-999
// The main loop passes (aRead), which is read into the (position) variable
// The value of (position) is used to determin the state of the WS2812 LEDs
void WS2812_Mid(int position)
{
    // This creates an integer named "LightMap" that remaps the analog pin range to the range of leds
    int LightMap = map(position, 0, 950, 0, NUM_LEDS);
 
    // Resets the LED values
    FastLED.clear();
 
    // Change led colors based on the value of the analog pin
    // Starts with blue, then green, then orange, then red. Two LEDs for each color
    for(int led = 0; led < LightMap; led++) 
    { 
      if(led < 2)leds[led] = CRGB::Blue;
      if(led >=2 & led < 4)leds[led] = CRGB::Green;
      if(led >=4 & led < 6)leds[led] = CRGB::Orange;
      if(led >=6)leds[led] = CRGB::Red;
     }
 
     FastLED.setBrightness(60);
     FastLED.show();
}

// This function is called if the value of (aRead) is 1000 or greater
// This fills the array twice each loop: First with Green/Red/Green/Red/Green/Red/Green/Red, then with R/G/R/G/R/G/R/G
void WS2812_High()
{
  FastLED.clear();
  leds[0] = 0xFF0000; //red
  leds[1] = 0x00FF00; //blue
  leds[2] = 0x0000FF; //green
  leds[3] = 0xFF0000;
  leds[4] = 0x00FF00;
  leds[5] = 0x0000FF;
  leds[6] = 0xFF0000;
  leds[7] = 0x00FF00; 
  FastLED.setBrightness(30);
  FastLED.show();
  delay(2000);

  FastLED.clear();
  leds[0] = 0x8000FF;//red + green = yellow
  leds[1] = 0x40FF00;//red + blue = purple
  leds[2] = 0x00FF80;//green + blue = aqua
  leds[3] = 0xFF0080;// red + (faded) green = orange
  leds[4] = 0xFF4000;// red + (faded) blue = pink?
  leds[5] = 0x00A0FF;// green + (faded) blue = ?
  leds[6] = 0x00FFA0;// blue + (faded) green = ?
  leds[7] = 0xC0C0FF;//red+green+blue = white?
  FastLED.setBrightness(30);
  FastLED.show();
  delay(2000);
}

// This loop reads the value of Analog Pin 1 into (aRead), then calls one of three functions (WS2812_Low, WS2812_Mid, or WS2812_High) depending on that value
// If it calls WS2812_Mid, it also passes the (aRead) value which is used to determine which lights should be lit in the strand
void loop()
{  
  int aRead = analogRead(1);
  PinDebug(aRead);

  if (aRead >= 0 & aRead < 50)
  {
    WS2812_Low();
  }
  
  else if (aRead >=50 & aRead < 1000) 
  {
    WS2812_Mid (aRead);
  }
  
   else 
  {
    WS2812_High();
  }

}

