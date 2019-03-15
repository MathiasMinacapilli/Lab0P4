#include <iostream>
#include <stdio.h>

#include "ClaseB.hpp"
#include "ClaseC.hpp"

class ClaseA;
class ClaseC;

class ClaseB {
private:
    int b;
    ClaseA* A;
    ClaseC* C;
public:
    //Setters
    void setb(int);
    void setA(ClaseA*);
    void setC(ClaseC*);
    
    //Getters
    int getb();
    ClaseA* getA();
    ClaseC* getC();
    
    //Constructor y Destructor
    ClaseB(int, ClaseA*, ClaseC*);
    ~ClaseB();
    
    void Imprimir(ClaseB);
};
