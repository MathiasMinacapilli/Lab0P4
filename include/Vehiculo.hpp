
class Vehiculo {
private:
    int nro_serie;
    float porcentaje_bateria, precio_base;
public:
    virtual float darPrecioViaje(int, int) = 0;
};


// Monopatin es subclase de Vehiculo
class Monopatin: public Vehiculo {
private:
    bool tieneLuces;
public:
    float darPrecioViaje(int, int);
};

enum TipoBici {Paseo, Montaña};
// Bicicleta subclase de Vehiculo
class Bicicleta: public Vehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
    float darPrecioViaje(int, int);
};

