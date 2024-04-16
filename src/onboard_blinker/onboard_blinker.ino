#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64




#define ONBOARD_LED  2
#define OLED_DATA 25
#define OLED_CLK 26

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int x;
int y;

void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.begin(9600);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 10);       // set position to display
  oled.println("Hallo Malte"); // set text
  oled.display();

  x = 0;
  y = 0;

}
void loop() {
  oled.clearDisplay();
  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(x, y);       // set position to display
  oled.println("Hallo Malte"); // set text
  oled.display();
  delay(200);
  x++;
  y++;
}
