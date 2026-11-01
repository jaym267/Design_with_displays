const int redPin = D6;
const int greenPin = D7;
const int bluePin = D8;
const int buttonPin = D1;
const int sliderPin = A0;

const byte colours[7][3] = {
  {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}
};
int colour = 0;
bool wasPressed = false;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // pressed reads LOW
}

void loop() {
  bool pressed = digitalRead(buttonPin) == LOW;
  if (pressed && !wasPressed) colour = (colour + 1) % 7;
  wasPressed = pressed;

  int level = analogRead(sliderPin) / 4;  // 0-1023 -> 0-255
  analogWrite(redPin, level * colours[colour][0]);
  analogWrite(greenPin, level * colours[colour][1]);
  analogWrite(bluePin, level * colours[colour][2]);
  delay(20);
}