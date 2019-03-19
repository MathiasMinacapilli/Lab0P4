#include "../include/ClaseA.hpp"
#include "../include/ClaseB.hpp"
#include "../include/ClaseC.hpp"


#include <iostream>
#include <stdio.h>

using namespace std;

void ClaseA::seta(int a) {
    this->a = a;
}

void ClaseA::setB(ClaseB* B) {
    this->B = B;
}

void ClaseA::setC(ClaseC* C) {
    this->C = C;
}

int ClaseA::geta() {
    return this->a;
}

ClaseB* ClaseA::getB() {
    return this->B;
}

ClaseC* ClaseA::getC() {
    return this->C;
}

//ClaseA::ClaseA(){}

ClaseA::ClaseA(int a, ClaseB* B, ClaseC* C) {
    this->a = a;
    this->B = B;
    this->C = C;
}

ClaseA::~ClaseA() {}

ostream &operator <<(ostream &o, ClaseA A) {
    o << "El nombre de la clase es: ClaseA y el valor del atributo es: " << A.geta();
    return o;
}
