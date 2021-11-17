#include "MenuPrincipal.h"
#include "rlutil.h"
#include "MenuProductos.h"
using namespace std;
using namespace rlutil;

void IniciarUI()
{
    setlocale(LC_ALL, "spanish");
    setColor(WHITE);
    setBackgroundColor(BLUE);
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
    cout << "                                                                TU SOLUCI�N ANTIHUMEDAD " << endl;

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
        cout << endl << endl << "OPCI�N: ";
        cin >> opcion;

        switch(opcion)
        {
            case 0:
                cout <<endl << endl<< endl;
                cout << "GRACIAS POR ELEGIRNOS" << endl;
                break;
            case 1:
                break;
            case 2:
                MenuProductos();
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << endl << endl << " ********  OPCI�N    INCORRECTA  ******** " << endl;
                anykey();
                break;
        }
    }
    while (opcion!=0);
}