
#ifndef _CLASEC_H_
#define _CLASEC_H_

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

#include "ClaseA.h"
#include "ClaseB.h"

#endif
