#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

void loop() {
    digitalWrite(OUTPIN, HIGH);
    delayMicroseconds(1136);
    digitalWrite(OUTPIN, LOW);
    delayMicroseconds(1136);
}
