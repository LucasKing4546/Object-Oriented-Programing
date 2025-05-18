//
// Created by Lucas on 3/31/2025.
//

#ifndef DERIVEDWAWES_H
#define DERIVEDWAWES_H
#include "AcousticWawe.h"

#endif //DERIVEDWAWES_H

class SineWave: public AcousticWave {
public:
    SineWave(float _freq, float _sample_rate, float _amp):AcousticWave{_freq, _amp, _sample_rate}{};
    void computeSamples(float freq, float sample_rate, float duration) override;
};
