//
// Created by Lucas on 3/23/2025.
//
#include "Complex.h"

void Complex::setReal(double real) {
    this->real = real;
}
void Complex::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}
void Complex::setDisplayType(DISPLAY_TYPE displayType) {
    this->displayType = displayType;
}

bool operator==(const Complex &c1, const Complex &c2) {
    return c1.real == c2.real && c1.imaginary == c2.imaginary;
}

bool operator!=(const Complex &c1, const Complex &c2) {
    return !(c1 == c2);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.getDisplayType() == Complex::RECTANGULAR_FORM)
        os << c.getReal() << " + " << c.getImaginary() << "i";
    else
        os << c.getMagnitude() << " * (cos" << c.getPhase() << " + i * sin" << c.getPhase() << ")";
    return os;
};
std::istream& operator>>(std::istream& is, Complex& c) {
    double real, imaginary;
    std::string DT;
    Complex::DISPLAY_TYPE displayType;
    std::cout << "Enter real and imaginary part: ";
    is >> real >> imaginary;
    std::cout << "Enter display type (rectangular or polar): ";
    is >> DT;
    if (DT == "rectangular")
        displayType = Complex::RECTANGULAR_FORM;
    else
        displayType = Complex::POLAR_FORM;
    c.setReal(real);
    c.setImaginary(imaginary);
    c.setDisplayType(displayType);
    return is;
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary(), c1.getDisplayType());
}
Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() - c2.getReal(), c1.getImaginary() - c2.getImaginary(), c1.getDisplayType());
}
Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() * c2.getReal() - c1.getImaginary() * c2.getImaginary(), c1.getReal() * c2.getImaginary() + c1.getImaginary() * c2.getReal(), c1.getDisplayType());
}
Complex operator*(const Complex& c1, double d) {
    return Complex(c1.getReal() * d, c1.getImaginary() * d, c1.getDisplayType());
}
Complex operator*(double d, const Complex& c1) {
    return Complex(c1.getReal() * d, c1.getImaginary() * d, c1.getDisplayType());
}