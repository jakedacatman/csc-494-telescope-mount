#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Button2.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
Button2 time_button;
Button2 clear_button;

void tap(Button2& b) {  
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print(b.wasPressedFor());
  display.display();
}

void clear(Button2& b) {  
  display.clearDisplay();
  display.display();
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  time_button.begin(D1);
  time_button.setTapHandler(tap);

  clear_button.begin(D2);
  clear_button.setTapHandler(clear);

  display.setCursor(0, 10);
  display.print("Initialized!");
  display.display();
}

void loop() {
  time_button.loop();
  clear_button.loop();
}