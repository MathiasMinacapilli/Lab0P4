#include "../include/ClaseA.hpp"
#include "../include/ClaseB.hpp"
#include "../include/ClaseC.hpp"


#include <iostream>
#include <stdio.h>

//setters

void ClaseB::setb(int b) {
    this->b = b;
}

void ClaseB::setA(ClaseA* A) {
    this->A = A;
}

void ClaseB::setC(ClaseC* C) {
    this->C = C;
}


//getters
int ClaseB::getb() {
    return this->b;
}

ClaseA* ClaseB::getA(){
    return this->A;
}

ClaseC* ClaseB::getC(){
    return this->C;
}

//constructor y destructor

ClaseB::ClaseB(int b, ClaseA *A, ClaseC *C){
    this->b=b;
    this->A=A;
    this->C=C;
}
ClaseB::~ClaseB() {}

