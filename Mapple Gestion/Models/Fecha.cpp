#include "Fecha.h"
#include <string>
#include <ctime>
using namespace std;

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

Fecha::Fecha(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

string Fecha::getStrFecha(){
    string strFecha;
    strFecha += to_string(_dia)+'/';
    strFecha += to_string(_mes)+'/';
    strFecha += to_string(_anio%100);
    return strFecha;
}

Fecha Fecha::operator+(int dias)
{
    Fecha resultado(*this);
    resultado._dia+=dias;
    while(resultado._dia>diasDelMes(resultado._mes, resultado._anio))
    {
        resultado._dia-=diasDelMes(resultado._mes, resultado._anio);
        resultado._mes++;
        if(resultado._mes>12)
        {
            resultado._mes=1;
            resultado._anio++;
        }
    }
    return resultado;
}

Fecha::diasDelMes(int mes, int anio)
{
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if (anio % 4 == 0)
                return 29;
            else
                return 28;
            break;
        default:
            return 30;
            break;
    }
}


bool Fecha::operator<=(Fecha fecha2)
{
    if(_anio<fecha2._anio)
        return true;
    if(_anio>fecha2._anio)
        return false;

    if(_mes<fecha2._mes)
        return true;
    if(_mes>fecha2._mes)
        return false;

    if(_dia>fecha2._dia)
        return false;
    return true;
}
