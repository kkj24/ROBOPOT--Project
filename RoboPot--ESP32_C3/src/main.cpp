#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 128

Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, -1);
RoboEyes<Adafruit_SSD1306> eyes(display);

byte err, address;
uint16_t REFRESH_RATE = 100;    // 100 Hz

void setup() {
    Wire.begin();

    for(address = 0; address < 127; address++) {
        Wire.beginTransmission(address);
        err = Wire.endTransmission();
    }

    display.begin(SSD1306_SWITCHCAPVCC, address);
    display.clearDisplay();
    display.setCursor(20, 25);
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.print("Initializing");

    delay(1000);

    display.clearDisplay();

    eyes.begin(DISPLAY_WIDTH, DISPLAY_HEIGHT, REFRESH_RATE);
    eyes.setAutoblinker(true);
    eyes.setCuriosity(true);
    eyes.setIdleMode(true);

    eyes.close();
    eyes.open();
}

void loop() {
    static uint8_t mood = 0;

    static uint32_t lastTime = 0;
    uint32_t nowTime = millis();

    enum MOOD {
        normal,
        angry,
        happy,
        confused
    };

    if(nowTime - lastTime >= 50000) {
        lastTime = nowTime;

        mood = random(0, 4);
    }

    switch(mood) {
        case normal:
        //
        break;

        case angry:
        //
        break;

        case happy:
        //
        break;

        case confused:
        //
        break;
    }

}