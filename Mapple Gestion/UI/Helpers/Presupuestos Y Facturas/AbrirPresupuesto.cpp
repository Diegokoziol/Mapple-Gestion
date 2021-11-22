#include "AbrirPresupuesto.h"
#include "EditarPresupuesto.h"
#include "../../rlutil.h"
#include <iomanip>
#include "../../../Managers/PresupuestoManager.h"
using namespace std;
using namespace rlutil;

void NuevoPresupuesto()
{
    cls();
    cout << left;
    PresupuestoModel nuevoPresupuesto;
    EditarPresupuesto(nuevoPresupuesto, "NUEVO PRESUPUESTO");
}

void AbrirPresupuesto()
{
    cls();
    int id;
    cout << "POR FAVOR, INGRESE EL ID DE PRESUPUESTO QUE DESEA ABRIR: ";
    cin >> id;
    while(cin.fail() || id<1)
    {
        cin.clear();
        cin.ignore();
        cout << "EL ID INGRESADO NO ES VÁLIDO, INTENTE NUEVAMENTE O INGRESE -1 PARA SALIR" << endl;
        cin >> id;
        if(id==-1) return;
    }
    PresupuestoModel presupuesto;
    while(!PresupuestoManager::cargar(id, presupuesto))
    {
        cout << "NO SE PUDO ABRIR EL PRESUPUESTO SOLICITADO" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
        if(getkey()==KEY_ESCAPE) return;
    }
    string encabezado= "PRESUPUESTO " + to_string(presupuesto.getId());
    EditarPresupuesto(presupuesto, encabezado.c_str());
}
