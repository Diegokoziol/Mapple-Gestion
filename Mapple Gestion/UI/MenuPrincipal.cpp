#include "MenuPrincipal.h"
#include "rlutil.h"
#include "EntradaNumerica.h"
#include "MenuProductos.h"
#include "MenuPresupuestosYFacturas.h"
#include "MenuGasto.h"
#include "Helpers/Balances/GenerarBalance.h"
#include <locale.h>///
using namespace std;
using namespace rlutil;

void IniciarUI()
{
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    setColor(WHITE);
    setBackgroundColor(BLUE);
    cout.precision(2);
    cout << fixed;
    Bienvenida();
}

void Bienvenida()
{
    cls();
    cout << endl << endl;
    cout << "   #######  #### ########  ########   #######   ######## #### ##     ##                   " << endl;
    cout << "   ##        ##  ##     ## ##     ## ##     ##  ##        ##   ##   ##                   " << endl;
    cout << "   ##        ##  ##     ## ##     ## ##     ##  ##        ##    ## ##                    " << endl;
    cout << "   ######    ##  ########  ########  ##     ##  ######    ##     ###                     " << endl;
    cout << "   ##        ##  ##     ## ##   ##   ##     ##  ##        ##    ## ##                    " << endl;
    cout << "   ##        ##  ##     ## ##    ##  ##     ##  ##        ##   ##   ##                   " << endl;
    cout << "   ##       #### ########  ##     ##  #######   ##       #### ##     ##                  " << endl<<endl<<endl;
    cout << "                                                                TU SOLUCIÓN ANTIHUMEDAD " << endl;

    cout << endl << endl<< endl<< endl;
    cout<<"                                     PARA INICIAR PRESIONE UNA TECLA CUALQUIERA"<<endl;
    anykey();
    MenuPrincipal();
}

void MenuPrincipal()
{
    int opcion;
    do
    {
        cls();
        cout<<endl;
        cout <<"                        MENU PRINCIPAL" <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl;
        cout <<"            1 - PRESUPUESTOS Y FACTURAS" << endl;
        cout <<"            2 - STOCK DE PRODUCTOS" << endl;
        cout <<"            3 - GASTOS" << endl;
        cout <<"            4 - BALANCES" << endl;
        cout <<"------------------------------------------------------------------ "<< endl;
        cout <<"            0 - SALIR." << endl;
        cout << endl << endl << "OPCIÓN: ";
        EntradaNumerica(opcion);
        switch(opcion)
        {
            case 0:
                cout <<endl << endl<< endl;
                cout << "GRACIAS POR ELEGIRNOS" << endl;
                anykey();
                break;
            case 1:
                MenuPresupuestosYFacturas();
                break;
            case 2:
                MenuProductos();
                break;
            case 3:
                MenuGasto();
                break;
            case 4:
                GenerarBalance();
                break;
            default:
                cout << endl << endl << " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                anykey();
                break;
        }
    }
    while (opcion!=0);
}
