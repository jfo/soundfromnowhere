int tempo = 80;

#define QUARTER  15000.0 / tempo
#define DOTTEDQUARTER  (QUARTER * 1.5)
#define EIGHTH  (QUARTER / 2)
#define DOTTEDEIGHTH  (EIGHTH * 1.5)
#define SIXTEENTH  (EIGHTH / 2)
#define HALF  (QUARTER * 2)
#define DOTTEDHALF  (QUARTER * 3)
#define WHOLE  (QUARTER * 4)

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
  play_melody(my_bonnie_lies_over_the_ocean, sizeof(my_bonnie_lies_over_the_ocean));
  delay(1000);
  play_melody(buddy_holly, sizeof(buddy_holly));
  delay(1000);
  tempo = 160;
}
