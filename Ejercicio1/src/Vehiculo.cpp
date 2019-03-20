
#include "../include/Vehiculo.hpp"
#include "../include/TipoBici.hpp"

//clase vehiculo (abstracta)

//constructor y destuctor
Vehiculo::Vehiculo(int num, float bateria, float pb){
	this->nro_serie=num;
	this->porcentaje_bateria=bateria;
	this->precio_base=pb;
}

Vehiculo::~Vehiculo(){}

//setters
void Vehiculo::set_nro_serie(int num){
	this->nro_serie=num;
}

void Vehiculo::set_porcentaje_bateria(float bateria){
	this->porcentaje_bateria=bateria;
}

void Vehiculo::set_precio_base(float pb){
	this->precio_base=pb;
}

//getters
int Vehiculo::get_nro_serie(){
	return this->nro_serie;
}

float Vehiculo::get_porcentaje_bateria(){
	return this->porcentaje_bateria;
}

float Vehiculo::get_precio_base(){
	return this->precio_base;
}
