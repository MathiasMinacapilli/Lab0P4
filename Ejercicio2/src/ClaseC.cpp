#include "../include/ClaseA.h"
#include "../include/ClaseB.h"
#include "../include/ClaseC.h"


#include <iostream>
#include <stdio.h>

void ClaseC::setc(int c) {
    this -> c = c;
}

void ClaseC::setB(ClaseB* B) {
    this -> B = B;
}

void ClaseC::setA(ClaseA* A) {
    this -> A = A;
}

int ClaseC::getc() {
    return this -> c;
}

ClaseB* ClaseC::getB() {
    return this -> B;
}

ClaseA* ClaseC::getA() {
    return this -> A;
}

ClaseC::ClaseC(int c, ClaseA* A, ClaseB* B) {
    this -> c = c;
    this -> A = A;
    this -> B = B;
}

ClaseC::~ClaseC() {
}

ostream &operator <<(ostream &o , ClaseC C) {
    o << "El nombre de la clase es: ClaseC  y el valor del atributo es: " << C.getc();
    return o;
}



 
