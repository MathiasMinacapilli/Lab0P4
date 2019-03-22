 
class DtFecha {
private:
    int dia, mes, anio;
public:
    // Constructor
    DtFecha(int=1, int=1, int=0);

    //Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    //~DtFecha()??

    //Sobrecarga de operadoradores
    bool operator>=(const DtFecha&);

    bool operator==(const DtFecha&);
};