#include "main.h"
#include <iostream>
#include <cmath>



namespace Objects{
    ComplexNumber::ComplexNumber(float real,float complex){
        this->real=real;
        this->complex=complex;
    }

    float ComplexNumber::magnitude() const{
        return std::sqrt((real*real)+(complex*complex));
    }

    float ComplexNumber::angle() const{
        return std::acos(real/magnitude());
    }

    ComplexNumber ComplexNumber::conjugate() const{
        ComplexNumber number(real,-complex);

        return number;
    }


    ComplexNumber ComplexNumber::operator+(ComplexNumber const&obj){
        ComplexNumber number{
            real=obj.real+real,
            complex=obj.complex+complex
        };

        return number;
    }

    ComplexNumber ComplexNumber::operator+(float const&obj){
        ComplexNumber number(obj+real,complex);

        return number;
    }

    ComplexNumber ComplexNumber::operator-(ComplexNumber const&obj){
        ComplexNumber number{
            real=real-obj.real,
            complex=complex-obj.complex
        };

        return number;
    }

    ComplexNumber ComplexNumber::operator-(float const&obj){
        ComplexNumber number(real-obj,complex);

        return number;
    }

    ComplexNumber ComplexNumber::operator*(ComplexNumber const&obj){
        float res_real=obj.real*real - obj.complex*complex;
        float res_complex=obj.real*complex + obj.complex*real;
        
        ComplexNumber number(res_real,res_complex);

        return number;
    }

    ComplexNumber ComplexNumber::operator*(float const&obj){
        ComplexNumber number(obj*real,obj*complex);

        return number;
    }

    ComplexNumber ComplexNumber::operator/(float const&obj){
        ComplexNumber number(this->real/obj,this->complex/obj);
        return number;
    }

    ComplexNumber ComplexNumber::operator/(ComplexNumber const&obj){
        ComplexNumber instance(this->real,this->complex);
        
        // instance/obj;
        ComplexNumber obj_conjugate= obj.conjugate();
        ComplexNumber result = (obj_conjugate * instance) / (obj_conjugate*obj).real;
        
        return result;
    }


    void ComplexNumber::print(PrintModes mode=EMPTY) const{
        float angle_value=angle();

        switch (mode)
        {
        case ARITHMETIC:
            std::cout << real << " + i" << complex << std::endl;
            break;
        
        case TRIGONOMETRIC:
            std::cout << "cos(" << angle_value << ") + i.sin(" << angle_value << ")" << std::endl;
            break;
        
        case EULER:
            std::cout << "e^(i." << angle_value<<")" << std::endl;
            break;
        
        default:
            std::cout << real << " + i." << complex << std::endl;
            break;
        }
    }
}

