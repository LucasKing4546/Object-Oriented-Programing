//
// Created by Lucas on 3/23/2025.
//
#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
    Complex stackComplex = Complex(5.0, 3.0,
        Complex::POLAR_FORM);
    cout << stackComplex << endl;
    cout << "Magnitude: " << stackComplex.getMagnitude() << endl;
    cout << "Phase: " << stackComplex.getPhase() << endl;
    auto* heapComplex = new Complex(2.0, 6.0, Complex::POLAR_FORM);
    cout << *heapComplex << endl;
    cout << "Magnitude: " << heapComplex->getMagnitude() << endl;
    cout << "Phase: " << heapComplex->getPhase() << endl;
    cout << "Addition: " << stackComplex + *heapComplex << endl;
    cout << "Subtraction: " << stackComplex - *heapComplex << endl;
    cout << "Multiplication: " << stackComplex * *heapComplex << endl;
    delete heapComplex;
    return 0;
}