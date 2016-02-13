#define OUTPIN 13

void setup() {
    pinMode(OUTPIN, OUTPUT);
}

float halfCycleDelay(float freq) {
    return 500000 / freq;
}

void square_wave(float freq, int duration){
    float delay_time = halfCycleDelay(freq);
    unsigned long start_time = millis();

    while(millis() < start_time + duration) {
        digitalWrite(OUTPIN, HIGH);
        delayMicroseconds(delay_time);
        digitalWrite(OUTPIN, LOW);
        delayMicroseconds(delay_time);
    }
}

float notes[15] = { 130.813, 146.832, 164.841, 174.614, 195.998, 220.000, 246.942, 261.626, 293.665, 329.628, 349.228, 391.995, 440.0, 493.883, 523.251 };

void loop() {
    for (int i = 0, i < 15, i++) {
        square_wave(notes[i], 500);
    }
}
