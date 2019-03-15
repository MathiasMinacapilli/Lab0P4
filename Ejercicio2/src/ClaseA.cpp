#include "../include/ClaseA.hpp"
#include "../include/ClaseB.hpp"
#include "../include/ClaseC.hpp"


#include <iostream>
#include <stdio.h>

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

ClaseA::

