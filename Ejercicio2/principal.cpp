/*** Laboratorio 0 de Programación 4 ***/
/*** Ejercicio 2 ***/
#include "include/ClaseA.h" 
#include "include/ClaseB.h"
#include "include/ClaseC.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int main(){
    
    //Construimos por defecto un objeto de cada clase 
    ClaseA obA1;
    ClaseB obB1;
    ClaseC obC1;
    
    //Se debe imprimir que el valor de A1 es 0
    
    cout << obA1 << "\n";
    
    //creamos punteros a objetos
    ClaseB* punteroB1 = &obB1;
    ClaseC* punteroC1 = &obC1;
    ClaseA* punteroA1 = &obA1;
    
    //probamos setters
    obA1.setB(punteroB1);
    obA1.setC(punteroC1);
    obA1.seta(5);
    
    obB1.setA(punteroA1);
    obB1.setC(punteroC1);
    obB1.setb(22);
    
    obC1.setA(punteroA1);
    obC1.setB(punteroB1);
    obC1.setc(13);
    
    //usamos Constructor por parametros para crear objeto de claseA 
    
    ClaseA obA2(71, punteroB1, &obC1);
    
    
    ///probamos links
    int b = obA2.getB()->getb();
    int c = obA2.getC()->getc();
    int b1 = obA1.getB()->getb();
    int c1 = obA1.getB()->getC()->getc();
    
    //imprimir
    
    cout << b << "\n";
    cout << c << "\n";
    cout << "El valor de B1 es: " << b1 << "\n";
    cout << "El valor de C1 es: " << c1 << "\n";
    cout << obA1;
    cout<<"\n";
    cout<< obB1 << "\n";
    cout << obA2 <<"\n";
    
    return 0;
}
