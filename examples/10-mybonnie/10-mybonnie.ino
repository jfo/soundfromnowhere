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
    for (int i = 0; i < size_of_melody / sizeof(float) * 2; i++) {
        square_wave(melody[i][0], melody[i][1]);
    }
}

//                  C        D        E        F        G        A        B        C        D        E        F        G        A      B        C
//                  0        1        2        3        4        5        6        7        8        9        10       11       12     13       14
float notes[15] = { 130.813, 146.832, 164.841, 174.614, 195.998, 220.000, 246.942, 261.626, 293.665, 329.628, 349.228, 391.995, 440.0, 493.883, 523.251 };
float my_bonnie_lies_over_the_ocean[38][2] = {
    {notes[4], 500.0},
    {notes[9], 750.0},
    {notes[8], 250.0},
    {notes[7], 500.0},
    {notes[8], 500.0},
    {notes[7], 500.0},
    {notes[5], 500.0},
    {notes[4], 500.0},
    {notes[2], 1000.0},
    {0.0,      1000.0},
    {notes[4], 500.0},
    {notes[9], 750.0},
    {notes[8], 250.0},
    {notes[7], 500.0},
    {notes[7], 500.0},
    {notes[6], 500.0},
    {notes[7], 500.0},
    {notes[8], 1500.0},
    {0,        1500.0},
    {notes[4], 500.0},
    {notes[9], 750.0},
    {notes[8], 250.0},
    {notes[7], 500.0},
    {notes[8], 500.0},
    {notes[7], 500.0},
    {notes[5], 500.0},
    {notes[4], 500.0},
    {notes[2], 1000.0},
    {0.0,      1000.0},
    {notes[4], 500.0},
    {notes[5], 500.0},
    {notes[8], 500.0},
    {notes[7], 500.0},
    {notes[6], 500.0},
    {notes[5], 500.0},
    {notes[6], 500.0},
    {notes[7], 1500.0},
    {0.0,      1000.0}
};


void loop() {
  play_melody(my_bonnie_lies_over_the_ocean, sizeof(my_bonnie_lies_over_the_ocean));
}
