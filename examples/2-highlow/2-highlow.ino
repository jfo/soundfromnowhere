#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

void loop() {
    digitalWrite(OUTPIN, HIGH);
    digitalWrite(OUTPIN, LOW);
}
