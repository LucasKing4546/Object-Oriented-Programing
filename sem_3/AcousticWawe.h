//
// Created by Lucas on 3/31/2025.
//

#ifndef ACOUSTICWAWE_H
#define ACOUSTICWAWE_H

#endif //ACOUSTICWAWE_H

class AcousticWave {
protected:
    float frequency{10};
    float amplitude{2};
    float sample_rate{1000};
    float* samples{nullptr};
    unsigned int number_of_samples{0};
public:
    AcousticWave() = default;
    AcousticWave(float _freq, float _amp, float _sample_rate):
    frequency(_freq),
    amplitude(_amp),
    sample_rate(_sample_rate)
    {};

    float getFrequency() const{ return this->frequency; };
    unsigned int getNumberOfSamples() const { return this->number_of_samples; };

    void computeSamples(float frequency, float sample_rate, float duration);
    ~AcousticWave() = default;

    AcousticWave(const AcousticWave& other) {
        this->frequency = other.frequency;
        this->amplitude = other.amplitude;
        this->number_of_samples = other.number_of_samples;
        this->sample_rate = other.sample_rate;
        float* new_array = new float[other.number_of_samples];
        for (int i = 0; i < number_of_samples; i++) {
            new_array[i] = other.samples[i];
        }
        this->samples = new_array;
    }

    AcousticWave& operator=(const AcousticWave& other) {
        if (this != &other) {
            this->frequency = other.frequency;
            this->amplitude = other.amplitude;
            this->number_of_samples = other.number_of_samples;
            this->sample_rate = other.sample_rate;
            delete[] this->samples;
            float* new_array = new float[other.number_of_samples];
            for (int i = 0; i < number_of_samples; i++) {
                new_array[i] = other.samples[i];
            }
            this->samples = new_array;
        }
        return *this;
    }
};
