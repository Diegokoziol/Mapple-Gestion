#include "MenuProductos.h"
#include "Helpers/Productos/CargarNuevoProducto.h"
#include "Helpers/Productos/ModificarPrecio.h"
#include "Helpers/Productos/RegistrarCompraDeProducto.h"
#include "Helpers/Productos/VerStock.h"
#include "rlutil.h"
#include "EntradaNumerica.h"
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
        cout << endl << endl << "OPCI�N: ";
        EntradaNumerica(opcion);
        switch(opcion)
        {
            case 0:
                break;
            case 1:
                CargarNuevoProducto();
                break;
            case 2:
                ModificarPrecio();
                break;
            case 3:
                RegistrarCompraProducto();
                break;
            case 4:
                VerStock();
                break;
            default:
                cout << endl << endl<< " ********  OPCI�N    INCORRECTA  ******** " << endl;
                anykey();
                break;
        }
    }
    while(opcion!=0);

}
