
#ifndef _CLASEA_HPP_
#define _CLASEA_HPP_


#include <iostream>
#include <stdio.h>

#include "ClaseB.hpp"
#include "ClaseC.hpp"
using namespace std;


class ClaseB;
class ClaseC;

class ClaseA {
private:
    int a;
    ClaseB* B;
    ClaseC* C;
public:
    //Setters
    void seta(int);
    void setB(ClaseB*);
    void setC(ClaseC*);
    
    //Getters
    int geta();
    ClaseB* getB();
    ClaseC* getC();
    
    //Constructor y Destructor
    //ClaseA();
    ClaseA(int=0, ClaseB* =nullptr, ClaseC* =nullptr);
    ~ClaseA();
};
ostream &operator <<(ostream &, ClaseA);

#endif
