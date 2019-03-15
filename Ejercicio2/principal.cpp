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
    
    //Creamos punteros a objetos
    ClaseA* punteroA1 = &obA1;
    ClaseB* punteroB1 = &obB1;
    ClaseC* punteroC1 = &obC1;
    
    //Probamos setters
    obA1.setB(punteroB1);
    obA1.setC(punteroC1);
    obA1.seta(1);
    
    obB1.setA(punteroA1);
    obB1.setC(punteroC1);
    obB1.setb(2);
    
    obC1.setA(punteroA1);
    obC1.setB(punteroB1);
    obC1.setc(3);
    
    //Usamos constructor por parametros para crear objeto de ClaseA 
    ClaseA obA2(4, punteroB1, &obC1);
    
    ///Probamos links
    int b1 = obA1.getB() -> getb();
    int b2 = obA2.getB() -> getb();
    int c1 = obA1.getC() -> getc();
    int c2 = obA2.getB() -> getC() -> getc();
   

    //Imprimir
    
    cout << "Los valores del camino (A-B-C-A) son: " << obA1.geta() 
    << "-" << obA1.getB() -> getb() 
    << "-" << obA1.getB() -> getC() -> getc() 
    << "-" << obA1.getB() -> getC() -> getA() -> geta() << "\n";
    
    cout << "Los valores del camino (A-C-B-A) son: " << obA1.geta() 
    << "-" << obA1.getC() -> getc() 
    << "-" << obA1.getC() -> getB() -> getb() 
    << "-" << obA1.getC() -> getB() -> getA() -> geta() << "\n";
    
    
    cout << "El valor de B1 desde A1 es: " << b1 << "\n";
    cout << "El valor de B1 desde A2 es: " << b2 << "\n";
    cout << "El valor de C1 desde A1 es: " << c1 << "\n";
    cout << "El valor de C1 desde A2 es: " << c2 << "\n";
    
    //Probamos la sobrecarga del operador <<
    cout << obA2 << "\n";
    
    return 0;
}
