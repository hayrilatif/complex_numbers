#include "main.cpp"

int main(void){
    Objects::ComplexNumber a(1.f,1.f);
    Objects::ComplexNumber b(1.f,1.0f);

    Objects::ComplexNumber c= a/b;

    (a*2).print(Objects::PrintModes::EULER);

    return 0;
}