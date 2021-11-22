#include "EditarPresupuesto.h"
#include "../../../Managers/PresupuestoManager.h"
#include "../../../Managers/ProductoManager.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"
#include <iomanip>
using namespace std;
using namespace rlutil;

void EditarPresupuesto(PresupuestoModel &presupuesto, const char* encabezado)
{
    int modo=1;
    while(modo)
    {
        cls();
        cout << encabezado;
        cout << right << setw(100-strlen(encabezado)) << presupuesto.getFecha().getStrFecha();
        cout << left << endl << endl;
        const int anchosColumnas[] = {10,35,10,20,20};
        TitulosColumnas(anchosColumnas);
        for(size_t i=0; i<20; i++)
        {
            if(i<presupuesto.getCantidadItems())
                ImprimirItem(presupuesto.getItem(i), anchosColumnas);
            else
                ImprimirItemVacio(anchosColumnas);
        }

        switch(modo)
        {
        case 1:
            modo = Modo1();
            break;
        case 3:
            modo = Modo3(presupuesto);
            break;
        case 5:
            modo = Modo5(presupuesto);
            break;
        case 7:
            modo = Modo7(presupuesto);
            break;
        case 9:
            modo = Modo9(presupuesto);
        default:
            modo=1;
            break;
        }
    }
}

void TitulosColumnas(const int* anchos)
{
    cout << setw(anchos[0]) << "CÓDIGO" << '|';
    cout << setw(anchos[1]) << "DESCRIPCIÓN" << '|';
    cout << setw(anchos[2]) << "CANTIDAD" << '|';
    cout << setw(anchos[3]) << "PRECIO UNITARIO" << '|';
    cout << setw(anchos[4]) << "TOTAL" << '|' << endl;

    for(int i=0; i<100; i++) cout << "~";
    cout << endl;
}

void ImprimirItemVacio(const int* anchos)
{
    cout << setw(anchos[0]) << "" << '|';
    cout << setw(anchos[1]) << "" << '|';
    cout << setw(anchos[2]) << "" << '|';
    cout << setw(anchos[3]) << "" << '|';
    cout << setw(anchos[4]) << "" << '|' << endl;
}

void ImprimirItem(ItemPresupuestoModel item, const int* anchos)
{
    cout << setw(anchos[0]) << item.getProducto().getCodigoProducto() << '|';
    cout << setw(anchos[1]) << item.getProducto().getDescripcionProducto() << '|';
    cout << setw(anchos[2]) << item.getCantidad() << '|';
    cout << setw(anchos[3]) << item.getMontoUnitario() << '|';
    cout << setw(anchos[4]) << item.getMontoTotal() << '|' << endl;
}

int Modo1()
{
    hidecursor();
    cout << "F3 - AGREGAR    F5 - ELIMINAR    F7 - CERRAR    F9 - ACTUALIZAR PRECIOS    F11 - GENERAR FACTURA" <<endl;
    switch(getkey())
    {
    case KEY_F3:
        return 3;
    case KEY_F5:
        return 5;
    case KEY_F7:
        return 7;
    case KEY_F9:
        return 9;
    case KEY_F11:
        return 11;
    default:
        return 1;
    }
}

int Modo3(PresupuestoModel &presupuesto)
{
    showcursor();

    if(presupuesto.vencido())
    {
        cout << "PARA MODIFICAR EL PRESUPUESTO, DEBE ESTAR DENTRO DEL PLAZO ESTIPULADO" << endl;
        cout << "PRESIONE ENTER PARA ACTUALIZAR EL PRESUPUESTO U OTRA TECLA PARA REGRESAR" << endl;
        if(getkey()==KEY_ENTER) return 9;
        else return 1;
    }

    if(presupuesto.getCantidadItems()>=20)
    {
        cout << "LO SENTIMOS, PERO NO SE ADMITEN MÁS DE 20 ITEMS POR PRESUPUESTO" << endl;
        anykey();
        return 1;
    }

    int cod, cant;
    cout << "CÓDIGO DE PRODUCTO: ";
    EntradaNumerica(cod);

    if(cod<1 || !ProductoManager::existe(cod))
    {
        cout << "EL CÓDIGO INGRESADO NO ES VÁLIDO" << endl;
        anykey();
        return 1;
    }

    ProductoModel producto;
    if(!ProductoManager::cargar(cod, producto))
    {
        cout << "HUBO UN PROBLEMA AL CARGAR EL PRODUCTO SOLICITADO" << endl;
        anykey();
        return 1;
    }

    cout << producto.getDescripcionProducto() << endl;

    cout << "INGRESE CANTIDAD: " << endl;
    EntradaNumerica(cant);
    while(cant<1)
    {
        cout << "POR FAVOR INGRESE UNA CANTIDAD POSITIVA" << endl;
        EntradaNumerica(cant);
    }

    presupuesto.agregarItem(ItemPresupuestoModel(producto, cant));

    return 1;
}

int Modo5(PresupuestoModel &presupuesto)
{
    showcursor();
    if(presupuesto.vencido())
    {
        cout << "PARA MODIFICAR EL PRESUPUESTO, DEBE ESTAR DENTRO DEL PLAZO ESTIPULADO" << endl;
        cout << "PRESIONE ENTER PARA ACTUALIZAR EL PRESUPUESTO U OTRA TECLA PARA REGRESAR" << endl;
        if(getkey()==KEY_ENTER) return 9;
        else return 1;
    }

    int cod;
    cout << "INGRESE EL CÓDIGO DEL PRODUCTO A QUITAR" << endl;
    EntradaNumerica(cod);
    presupuesto.quitarItem(cod);
    return 1;
}

int Modo7(PresupuestoModel &presupuesto)
{
    cls();
    cout << "¿DESEA GUARDAR LOS CAMBIOS?" << endl;
    cout << "ENTER - GUARDAR CAMBIOS    N - DESCARTAR CAMBIOS    ESCAPE - VOLVER A EDITAR" << endl;
    showcursor();

    bool guardado;
    switch(getkey())
    {
    case KEY_ENTER:
        guardado = false;
        if(presupuesto.getPlazo()==0)
        {
            int plazo=0;
            while(plazo<1 || plazo>90)
            {
                if(plazo==-1) return 1;
                cout << "POR FAVOR, INGRESE UN PLAZO DE VALIDEZ DE ENTRE 1 Y 90 DÍAS O -1 PARA REGRESAR" << endl;
                EntradaNumerica(plazo);
            }
        }

        while(!guardado)
        {
            if(presupuesto.getId()==0)
                guardado = PresupuestoManager::guardarNuevo(presupuesto);
            else
                guardado = PresupuestoManager::sobreescribir(presupuesto);

            cout << endl << endl;
            if(!guardado)
            {
                cout << "HUBO UN PROBLEMA AL GUARDAR LOS CAMBIOS" << endl;
                cout << "PRESIONE ESCAPE PARA REGRESAR U OTRA TECLA PARA REINTENTAR" << endl;
                if(getkey()==KEY_ESCAPE) return 1;
            }
            else
            {
                cout << "PRESUPUESTO GUARDADO" << endl;
                cout << "ID DEL PRESUPUESTO: " << presupuesto.getId() << endl;
                cout << "POR FAVOR GUARDE ESTE NÚMERO PARA VOLVER A ACCEDER A ÉL" << endl;
                anykey();
            }
        }
        return 0;
    case 'n':
    case 'N':
        return 0;
    case KEY_ESCAPE:
        return 1;
    default:
        return 7;
    }
}

int Modo9(PresupuestoModel &presupuesto)
{
    int plazo;
    cout << "POR FAVOR INDIQUE EL NUEVO PLAZO (ENTRE 1 Y 90 DÍAS) O -1 PARA REGRESAR" << endl;
    cout << "TENGA EN CUENTA QUE LA FECHA DEL PRESUPUESTO DE ACTUALIZARÁ AL DÍA DE HOY" << endl;
    EntradaNumerica(plazo);

    while(plazo<1 || plazo > 90)
    {
        if(plazo==-1) return 1;
        cout << endl;
        cout << "DEBE INGRESAR UNA CANTIDAD DE DÍAS ENTRE 1 Y 90 O -1 PARA REGRESAR" << endl;
        cout << "TENGA EN CUENTA QUE LA FECHA DEL PRESUPUESTO DE ACTUALIZARÁ AL DÍA DE HOY" << endl;
        EntradaNumerica(plazo);
    }

    presupuesto.recalcular();
    presupuesto.setPlazo(plazo);
    presupuesto.setFecha(Fecha());
    return 1;
}
