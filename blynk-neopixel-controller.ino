#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define PIN D6
#define NUMPIXELS 45
#define BLYNK_PRINT Serial


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
Serial.begin(9600);
Blynk.begin(AUTH_CODE, SSID, PASSWORD);
pixels.begin();
}
BLYNK_WRITE(V1)
{
 int brightness = param.asInt();
 pixels.setBrightness(brightness); 
 pixels.show();
}

BLYNK_WRITE(V2)
{
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(R,G,B));
  }
  pixels.show();
}

void loop()
{
Blynk.run();
}
