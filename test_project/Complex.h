//
// Created by Lucas on 3/23/2025.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
#include <iostream>
#endif //COMPLEX_H

class Complex {
    public:
        enum DISPLAY_TYPE {RECTANGULAR_FORM, POLAR_FORM};

        Complex(): real(0), imaginary(0), displayType(RECTANGULAR_FORM) {};;
        Complex(double real, double imaginary, DISPLAY_TYPE displayType):real(real), imaginary(imaginary), displayType(displayType) {};

        double getReal() const {return real;};
        double getImaginary() const {return imaginary;};
        void setReal(double real);
        void setImaginary(double imaginary);

        DISPLAY_TYPE getDisplayType() const {return displayType;};
        void setDisplayType(DISPLAY_TYPE displayType);

        friend bool operator==(const Complex &, const Complex &);
        friend bool operator!=(const Complex &, const Complex &);
        friend std::ostream& operator<<(std::ostream& os, const Complex&);
        friend std::istream& operator>>(std::istream& is, Complex&);
        friend Complex operator+(const Complex&, const Complex&);
        friend Complex operator-(const Complex&, const Complex&);
        friend Complex operator*(const Complex&, const Complex&);
        friend Complex operator*(const Complex&, double);
        friend Complex operator*(double, const Complex&);

        double getMagnitude() const {
            return sqrt(real * real + imaginary * imaginary);
        };
        double getPhase() const {
            return atan2(imaginary, real);
        }
    private:
        double real;
        double imaginary;
        DISPLAY_TYPE displayType;
};