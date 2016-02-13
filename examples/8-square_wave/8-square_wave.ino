#define OUTPIN 13

void setup() {
        pinMode(OUTPIN, OUTPUT);
}

float halfCycleDelay(float freq) {
        return 500000 / freq;
}

void square_wave(float freq){
    float delay_time = halfCycleDelay(freq);
    unsigned long start_time = millis();

    while(millis() < start_time + 1000) {
        digitalWrite(OUTPIN, HIGH);
        delayMicroseconds(delay_time);
        digitalWrite(OUTPIN, LOW);
        delayMicroseconds(delay_time);
    }
}

void loop() {
    square_wave(440.0);
    delay(1000);
}
