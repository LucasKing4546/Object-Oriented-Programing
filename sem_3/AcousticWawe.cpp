//
// Created by Lucas on 3/31/2025.
//
#include "AcousticWawe.h"

void AcousticWave::computeSamples(float frequency, float sample_rate, float duration) {
    this->number_of_samples = unsigned int(sample_rate * duration);
    this->samples = new float[this->number_of_samples];
    for (int i = 0; i < number_of_samples; i++) {
        this->samples[i] = 0;
    }
}


