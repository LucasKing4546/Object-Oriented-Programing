//
// Created by Lucas on 3/31/2025.
//
#include <math.h>

#include "DerivedWawes.h"

void SineWave::computeSamples(float freq, float sample_rate, float duration) {
    AcousticWave::computeSamples(freq, sample_rate, duration);
    float step = 1/sample_rate;
    for (int i=0; i < this->number_of_samples; i++) {
        this->samples[i] = this->amplitude * sin(2 * M_PI * this->frequency * i * step);
    }
}


