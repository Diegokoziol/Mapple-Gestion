#include "MenuPresupuestosYFacturas.h"
#include "Helpers/Presupuestos Y Facturas/AbrirPresupuesto.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;

void MenuPresupuestosYFacturas()
{
    int opcion;
    do
    {
        cls();
        cout <<endl;
        cout <<"                      PRESUPUESTOS Y FACTURAS" <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - NUEVO PRESUPUESTO" << endl << endl;
        cout <<"            2 - ABRIR PRESUPUESTO" << endl << endl;
        cout <<"            3 - VER FACTURAS" << endl << endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            opcion=-1;
        }
        switch(opcion)
        {
            case 0:
                break;
            case 1:
                NuevoPresupuesto();
                break;
            case 2:
                AbrirPresupuesto();
                break;
            case 3:
                break;
            default:
                cout << endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                anykey();
                break;
        }
    }
    while(opcion!=0);

}
