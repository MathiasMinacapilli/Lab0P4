#include "../include/Bicicleta.hpp"

//clase Bicicleta

//constructor con parametros
Bicicleta::Bicicleta(int num, float bateria, float pb, TipoBici bici, int cambios)
	:Vehiculo(num, bateria, pb) {
		this->tipo=bici;
		this->cant_cambios=cambios;
}

//getters
TipoBici Bicicleta::get_tipo() const{
	return this->tipo;
}

int Bicicleta::get_cant_cambios() const{
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
	return (get_precio_base()*distancia);
}

//destructor
Bicicleta::~Bicicleta()
	{
		
}
