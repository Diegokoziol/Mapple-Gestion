#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>
using namespace std;

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
    int diasDelMes(int mes, int anio);
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    string getStrFecha();
    Fecha operator+(int dias);
    bool operator<=(Fecha fecha2);
};

#endif // FECHA_H_INCLUDED
