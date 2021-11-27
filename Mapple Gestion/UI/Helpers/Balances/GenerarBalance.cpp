#include "GenerarBalance.h"
#include "../../../Managers/BalanceManager.h"
#include "../../../Models/Fecha.h"
#include "../../EntradaNumerica.h"
#include "../../rlutil.h"
using namespace rlutil;
using namespace std;

void GenerarBalance()
{
    cls();
    cout << "*** GENERAR BALANCE ***" << endl << endl;
    int anio, mes;
    anio = EntradaAnioReporte();
    if(anio==-1) return;
    mes = EntradaMesReporte(anio);
    if(mes==-1) return;

    string titulo = "Balance " + to_string(mes) + "-" + to_string(anio) + ".csv";
    if(ConfirmacionReemplazar(titulo))
    {
        cout << endl;
        if(BalanceManager::guardarNuevo(anio, mes))
            cout << "BALANCE GENERADO EXITOSAMENTE" << endl;
        else
            cout << "HUBO UN PROBLEMA AL GENERAR EL BALANCE" << endl;
        anykey();
    }
    return;
}

int EntradaAnioReporte()
{
    int anio;
    Fecha hoy;
    cout << "INGRESE EL AÑO DEL PERÍODO QUE QUIERE EXPORTAR O -1 PARA REGRESAR" << endl;
    EntradaNumerica(anio);
    while(anio<0 || anio > hoy.getAnio())
    {
        if(anio > hoy.getAnio())
        {
            cout << "NO PUEDE GENERAR UN REPORTE DE UN AÑO POSTERIOR AL ACTUAL" << endl;
        }
        else
        {
            if(anio<0)
            {
                if(anio==-1) return -1;
                cout << "EL AÑO DEBE SER UN NÚMERO POSITIVO" << endl;
            }
        }
        cout << "POR FAVOR, VUELVA A INGRESAR EL AÑO O -1 PARA REGRESAR" << endl;
        EntradaNumerica(anio);
    }
    return anio;
}

int EntradaMesReporte(int anio)
{
    int mes;
    Fecha hoy;
    cout << "INGRESE EL MES DEL PERÍODO QUE QUIERE EXPORTAR O -1 PARA REGRESAR" << endl;
    EntradaNumerica(mes);
    while(mes<1 || mes > 12 || (anio==hoy.getAnio() && mes > hoy.getMes()))
    {
        if(mes<1 || mes > 12)
        {
            if(mes==-1) return -1;
            cout << "EL NÚMERO DE MES NO ES VÁLIDO (1 A 12)" << endl;
        }
        else
        {
            if(anio==hoy.getAnio() && mes > hoy.getMes())
            {
                cout << "NO PUEDE GENERAR UN REPORTE DE UN MES POSTERIOR AL ACTUAL" << endl;
            }
        }
        cout << "POR FAVOR, VUELVA A INGRESAR EL MES O -1 PARA REGRESAR" << endl;
        EntradaNumerica(mes);
    }
    return mes;
}

bool ConfirmacionReemplazar(string titulo)
{
    cout << endl << "ESTE REPORTE SE GENERARÁ EN EL DIRECTORIO DEL PROGRAMA CON EL NOMBRE " << titulo << endl;
    cout << "CUALQUIER ARCHIVO EN ESE DIRECTORIO CON ESE NOMBRE SERÁ SOBREESCRITO" << endl;
    cout << endl << "¿DESEA CONTINUAR?" << endl;
    cout << "PRESIONE ENTER PARA CONFIRMAR U OTRA TECLA PARA REGRESAR" << endl;
    return getkey()==KEY_ENTER;
}
