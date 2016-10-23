#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

void loop() {
    digitalWrite(OUTPIN, HIGH);
    delay(500);
    digitalWrite(OUTPIN, LOW);
    delay(500);
}
