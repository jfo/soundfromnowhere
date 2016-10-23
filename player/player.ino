#include "notes.h"
#include "melodies.h"

#define OUTPIN 13

void setup() {
    pinMode(OUTPIN, OUTPUT);
}

float halfCycleDelay(float freq) {
    return 500000 / freq;
}

void square_wave(float freq, float duration){
    if (freq == 0) {
        delay(duration);
    } else {
        float delay_time = halfCycleDelay(freq);
        unsigned long start_time = millis();

        while(millis() < start_time + duration) {
            digitalWrite(OUTPIN, HIGH);
            delayMicroseconds(delay_time);
            digitalWrite(OUTPIN, LOW);
            delayMicroseconds(delay_time);
        }
    }
}

void play_melody(float melody[][2], size_t size_of_melody) {
    for (int i = 0; i < size_of_melody / (sizeof(float) * 2); i++) {
        square_wave(melody[i][0], melody[i][1]);
    }
}

void loop() {
  play_melody(daisy, sizeof(daisy));
  // play_melody(my_bonnie_lies_over_the_ocean, sizeof(my_bonnie_lies_over_the_ocean));
  // play_melody(buddy_holly, sizeof(buddy_holly));
}
