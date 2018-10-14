#include <Adafruit_NeoPixel.h>

#define Count 1200
#define Pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(Count, Pin, NEO_GRB + NEO_KHZ800);

#define Brightness 5//Set brightness to 1/10th
#define Full (255/Brightness)
#define Half (128/Brightness)


//Create scrolling red and white candy cane stripes.
//Try adjusting the width in pixels for various results.
//Value "sets" should evenly divide into strand length
void CandyCane  (uint32_t c1, uint32_t c2,int sets, int width, int wait) {
  int L;
  for (int j = 0; j < (sets * width); j++) {
    for (int i = 0; i < strip.numPixels(); i++) {
      L = strip.numPixels() - i - 1;
      if ( ((i + j) % (width * 2) ) < width)
        //pink 
        //strip.setPixelColor(L, Full, 105/Brightness, 180/Brightness);
        //Orange 
        //strip.setPixelColor(L, Full, 51/Brightness, 0/Brightness); 
        strip.setPixelColor(i,c1);        
      else
        //White
        //strip.setPixelColor(L, Full, Full, Full);
        //purple
        //strip.setPixelColor(L, 102/Brightness, 0/Brightness, 102/Brightness);  
        strip.setPixelColor(i,c2);       
    };
    strip.show();
    delay(wait);
  };
};

// Set all pixels to the same color
void singleColor(uint32_t c,int wait){
    for (int i=0;i<Count;i++) {
      strip.setPixelColor(i,c);   
    }
    strip.show();
    delay(wait); 
}

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(1234);//Set up random number generator
}

void loop() {
  CandyCane(strip.Color(Full, 51/Brightness, 0/Brightness),strip.Color(102/Brightness, 0/Brightness, 102/Brightness),30, 16, 50); //Orange, Purple, 30 sets, 16 pixels wide, 50us delay
  singleColor(strip.Color(0, 0, 0), 5000); // Black   
  singleColor(strip.Color(Full, Full, Full), 50); // White
  singleColor(strip.Color(0, 0, 0), 500); // Black 
  singleColor(strip.Color(Full, Full, Full), 50); // White
  singleColor(strip.Color(0, 0, 0), 5000); // Black   
  singleColor(strip.Color(Full , 0, 0), 500); // Red  
  singleColor(strip.Color(Full*.875, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.75, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.625, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.5, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.375, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.25, 0, 0), 500); // Red
  singleColor(strip.Color(Full*.125, 0, 0), 5000); // Red
  singleColor(strip.Color(0, 0, 0), 5000); // Black        
  singleColor(strip.Color(Full, Full, Full), 25); // White
  singleColor(strip.Color(0, 0, 0), 5000); // Black 

}
