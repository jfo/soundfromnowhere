#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

float halfCycleDelay(float freq) {
        return 500000 / freq;
        // OR:
        // return ((1/freq) * 1000000) / 2;
}

void loop() {
    float delay_time = halfCycleDelay(440.0);
    digitalWrite(OUTPIN, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(OUTPIN, LOW);
    delayMicroseconds(delay_time);
}
