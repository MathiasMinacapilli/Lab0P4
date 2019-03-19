
#ifndef _CLASEC_HPP_
#define _CLASEC_HPP_

#include <iostream>
#include <stdio.h>

using namespace std;
class ClaseA;
class ClaseB;

class ClaseC {
private:
    int c;
    ClaseA* A;
    ClaseB* B;
public:
    //Setters
    void setc(int);
    void setA(ClaseA*);
    void setB(ClaseB*);
    
    //Getters
    int getc();
    ClaseA* getA();
    ClaseB* getB();
    
    //Constructor y Destructor
    ClaseC(int=0, ClaseA* =nullptr, ClaseB* =nullptr);
    ~ClaseC();
};

ostream &operator <<(ostream &, ClaseC);

#include "ClaseA.hpp"
#include "ClaseB.hpp"

#endif
