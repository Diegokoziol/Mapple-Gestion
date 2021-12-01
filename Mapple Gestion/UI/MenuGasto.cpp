#include <iostream>
#include "rlutil.h"
#include "EntradaNumerica.h"
#include "MenuGasto.h"
#include "Helpers/Gastos/AgregarGasto.h"
#include "Helpers/Gastos/MostrarGastos.h"

using namespace rlutil;
using namespace std;

void MenuGasto(){
    int opcion;
    do{
        cls();
        cout <<endl;
        cout <<"                        GASTOS " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - CARGAR NUEVO GASTO" << endl<< endl;
        cout <<"            2 - VER GASTOS REALIZADOS" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";

        EntradaNumerica(opcion);
        switch(opcion){
                    case 0:
                        break;
                    case 1:
                        cout <<"                   CARGAR NUEVO GASTO"<<endl;
                        cout<<"------------------------------------------------------------------"<<endl;
                        AgregarGasto();
                        cls();
                        break;

                    case 2:
                        cout <<"                VER GASTOS REALIZADOS"<<endl;
                        MostrarGastos();
                        cls();
                    break;
                    default:
                        cout << endl << endl << " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout << endl << endl << endl;
                    break;

            }
  }
   while (opcion!=0);
}






