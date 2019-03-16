
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


//clase Monopatin

//constructor con parametros
Monopatin::Monopatin(int num, float bateria, float pb, bool luces)
	:Vehiculo(num, bateria, pb){
		this->tieneLuces=luces;

}

//getter
bool Monopatin::get_luces(){
	return this->tieneLuces;
}

//setter
void Monopatin::set_tieneLuces(bool luces){
	this->tieneLuces = luces;
}

//operacion polimorfica
float Monopatin::darPrecioViaje(int duracion, int distancia){
	if (tieneLuces)
		return ((0.5*duracion) + (distancia*get_precio_base()));
	else //no tiene luces 
		return distancia*get_precio_base();
}


//destructor
Monopatin::~Monopatin(){}

//clase Bicicleta

//constructor con parametros
Bicicleta::Bicicleta(int num, int bateria, int pb, TipoBici bici, int cambios)
	:Vehiculo(num, bateria, pb) {
		this->tipo=bici;
		this->cant_cambios=cambios;
}

//getters
TipoBici Bicicleta::get_tipo(){
	return this->tipo;
}

int Bicicleta::get_cant_cambios(){
	return this->cant_cambios;
}

//setters
void Bicicleta::set_tipo(TipoBici bici){
	this->tipo = bici;
}
void Bicicleta::set_cant_cambios(int cambios){
	this->cant_cambios = cambios;
}

//operacion polimorfica
float Bicicleta::darPrecioViaje(int duracion, int distancia){
	return (get_precio_base()*distancia)
}



//destructor 
Bicicleta::~Bicicleta() {}