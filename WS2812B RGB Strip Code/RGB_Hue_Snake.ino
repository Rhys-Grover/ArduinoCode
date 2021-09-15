#include <FastLED.h>

#define numled 300
#define datapin 10

CRGB leds[numled];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<WS2812,datapin,RGB>(leds,numled);
	LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < numled; i++) { leds[i].nscale8(250); } }

void loop() { 
	static uint8_t hue = 0;
	for(int i = 0; i < numled; i++) {
		leds[i] = CHSV(hue++, 255, 255);
		FastLED.show(); 
		fadeall();
		delay(10);
	}
