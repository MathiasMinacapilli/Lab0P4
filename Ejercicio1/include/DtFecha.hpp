 
class DtFecha {
private:
    int dia, mes, anio;
public:
    // Constructor
    DtFecha(int=1, int=1, int=0);

    //Getters
    int getDia();
    int getMes();
    int getAnio();

    //~DtFecha()??
};

//Sobrecarga el operador >=
bool operator>= (DtFecha, DtFecha);
