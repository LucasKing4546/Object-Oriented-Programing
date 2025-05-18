 #include <iostream>

#include "AcousticWawe.h"

int main() {
    AcousticWave w {5, 2, 100};
    AcousticWave w2;
    std::cout << w2.getFrequency() << ' ' << w.getFrequency();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.