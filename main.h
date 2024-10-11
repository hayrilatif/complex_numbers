#pragma once

namespace Objects{
    enum PrintModes{
        ARITHMETIC,TRIGONOMETRIC,EULER,EMPTY
    };

    class ComplexNumber{
        public:
        float real,complex;

        ComplexNumber(float real,float complex);
        void print(PrintModes mode) const;


        float magnitude(void) const;
        float angle(void) const;
        ComplexNumber conjugate(void) const;
        

        ComplexNumber operator+(ComplexNumber const &obj);
        ComplexNumber operator-(ComplexNumber const &obj);
        ComplexNumber operator+(float const &obj);
        ComplexNumber operator-(float const &obj);

        ComplexNumber operator*(ComplexNumber const &obj);
        ComplexNumber operator*(float const &obj);

        ComplexNumber operator/(float const &obj);
        ComplexNumber operator/(ComplexNumber const &obj);
    };
}
