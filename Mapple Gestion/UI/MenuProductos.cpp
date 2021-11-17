#include "MenuProductos.h"
#include "Helpers/Productos/CargarNuevoProducto.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;

void MenuProductos()
{
    int opcion;
    do
    {
        cls();
        cout <<endl;
        cout <<"                        STOCK DE PRODUCTOS " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - CARGAR NUEVO PRODUCTO" << endl<< endl;
        cout <<"            2 - ACTUALIZAR PRECIO PRODUCTO" << endl<<endl;
        cout <<"            3 - REGISTRAR COMPRA DE PRODUCTO" << endl<<endl;
        cout <<"            4 - VER STOCK" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;
        switch(opcion)
        {
            case 0:
                break;
            case 1:
                CargarNuevoProducto();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                anykey();
                break;
        }
    }
    while(opcion!=0);

}
