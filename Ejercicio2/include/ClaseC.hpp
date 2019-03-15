#include <iostream>
#include <stdio.h>

#include "ClaseA.hpp"
#include "ClaseB.hpp"

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
    ClaseC(int, ClaseA*, ClaseB*);
    ~ClaseC();
};

ostream &operator <<(ostream &, ClaseC);
