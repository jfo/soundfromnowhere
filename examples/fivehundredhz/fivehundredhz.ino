#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

void loop() {
    digitalWrite(OUTPIN, HIGH);
    delay(1);
    digitalWrite(OUTPIN, LOW);
    delay(1);
}

// OR, same thing in microseconds:
// void loop() {
//     digitalWrite(OUTPIN, HIGH);
//     delayMicroseconds(1000);
//     digitalWrite(OUTPIN, LOW);
//     delayMicroseconds(1000);
// }
