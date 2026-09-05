#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

// =================================================
// PIN DEFINITIONS
// =================================================

const int servoPin = 18;
const int buttonPin = 4;

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

// =================================================
// OBJECTS
// =================================================

Servo myServo;

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// =================================================
// SETTINGS
// =================================================

// Servo movement speed
const int servoDelay = 30;

// Maximum number of servo cycles
const int MAX_CYCLES = 4;

// Time allowed for additional button presses
const unsigned long PRESS_WINDOW = 1500;

// =================================================
// VARIABLES
// =================================================

int pressCount = 0;


// =================================================
// SETUP
// =================================================

void setup() {

  Serial.begin(115200);

  // -------------------------
  // Button
  // -------------------------

  pinMode(buttonPin, INPUT_PULLUP);

  // -------------------------
  // Servo
  // -------------------------

  myServo.setPeriodHertz(50);

  myServo.attach(
    servoPin,
    500,
    2400
  );

  // Start at center
  myServo.write(90);

  // -------------------------
  // OLED
  // -------------------------

  Wire.begin(21, 22);

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS)) {

    Serial.println("OLED NOT FOUND!");

    while (1);
  }

  Serial.println("OLED READY");

  // Clear OLED initially
  display.clearDisplay();
  display.display();
}


// =================================================
// LOOP
// =================================================

void loop() {

  // =================================================
  // WAIT FOR FIRST BUTTON PRESS
  // =================================================

  if (digitalRead(buttonPin) == LOW) {

    delay(50);  // Debounce

    if (digitalRead(buttonPin) == LOW) {

      // First press
      pressCount = 1;

      Serial.println("Press 1 detected");

      // Wait for release
      while (digitalRead(buttonPin) == LOW) {
      }

      delay(50);

      // Record time
      unsigned long lastPressTime = millis();


      // =================================================
      // LOOK FOR ADDITIONAL QUICK PRESSES
      // =================================================

      while (millis() - lastPressTime < PRESS_WINDOW) {

        if (digitalRead(buttonPin) == LOW) {

          delay(50);

          if (digitalRead(buttonPin) == LOW) {

            pressCount++;

            Serial.print("Press detected: ");
            Serial.println(pressCount);

            lastPressTime = millis();

            // Wait for release
            while (digitalRead(buttonPin) == LOW) {
            }

            delay(50);
          }
        }
      }


      // =================================================
      // LIMIT TO 4 CYCLES
      // =================================================

      int cyclesToPerform = pressCount;

      if (cyclesToPerform > MAX_CYCLES) {
        cyclesToPerform = MAX_CYCLES;
      }

      Serial.print("Cycles to perform: ");
      Serial.println(cyclesToPerform);


      // =================================================
      // PERFORM SERVO SWEEP
      // =================================================

      for (int cycle = 0;
           cycle < cyclesToPerform;
           cycle++) {

        Serial.print("Cycle ");
        Serial.println(cycle + 1);


        // -----------------------------------------
        // CENTER → RIGHT
        // 90° → 180°
        // -----------------------------------------

        for (int angle = 90;
             angle <= 180;
             angle++) {

          myServo.write(angle);
          delay(servoDelay);
        }


        // -----------------------------------------
        // RIGHT → CENTER
        // 180° → 90°
        // -----------------------------------------

        for (int angle = 180;
             angle >= 90;
             angle--) {

          myServo.write(angle);
          delay(servoDelay);
        }


        // -----------------------------------------
        // CENTER → LEFT
        // 90° → 0°
        // -----------------------------------------

        for (int angle = 90;
             angle >= 0;
             angle--) {

          myServo.write(angle);
          delay(servoDelay);
        }


        // -----------------------------------------
        // LEFT → CENTER
        // 0° → 90°
        // -----------------------------------------

        for (int angle = 0;
             angle <= 90;
             angle++) {

          myServo.write(angle);
          delay(servoDelay);
        }


        // Make sure servo is centered
        myServo.write(90);

        delay(100);
      }


      // =================================================
      // OLED MESSAGE
      // =================================================

      display.clearDisplay();

      display.setTextColor(SSD1306_WHITE);

      display.setTextSize(2);

      display.setCursor(10, 20);


      if (pressCount == 1) {

        display.println("80% clear");

      }

      else if (pressCount == 2) {

        display.println("89% clear");

      }

      else if (pressCount == 3) {

        display.println("98% clear");

      }

      else {

        // 4 OR MORE PRESSES

        display.println("99% clear");
      }


      display.display();


      // =================================================
      // RESET
      // =================================================

      pressCount = 0;
    }
  }
}
