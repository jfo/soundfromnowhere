#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

void loop() {
    int no_whammies = random(100);
    if (no_whammies > 50) {
        digitalWrite(OUTPIN, HIGH);
    } else {
        digitalWrite(OUTPIN, LOW);
    }
}
