#include "EditarPresupuesto.h"
#include "GenericoPresupuestoYFactura.h"
#include "../../../Managers/PresupuestoManager.h"
#include "../../../Managers/ProductoManager.h"
#include "../../../Managers/ClienteManager.h"
#include "../../../Managers/FacturaManager.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"
#include "../../EntradaCadena.h"
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

        string msjVencido;
        if(presupuesto.getPlazo()!=0)
        {
            if(presupuesto.vencido())
                msjVencido = "PRESUPUESTO FUERA DE T�RMINO";
            else
                msjVencido = "VENCIMIENTO DEL PLAZO: " + (presupuesto.getFecha()+presupuesto.getPlazo()).getStrFecha();
            cout << msjVencido;
        }
        cout << right << setw(100-msjVencido.size()) << presupuesto.getMontoTotal() << endl << endl;

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
            break;
        case 11:
            modo = Modo11(presupuesto);
            break;
        default:
            modo=1;
            break;
        }
    }
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
        cout << "LO SENTIMOS, PERO NO SE ADMITEN M�S DE 20 ITEMS POR PRESUPUESTO" << endl;
        anykey();
        return 1;
    }

    int cod, cant;
    cout << "C�DIGO DE PRODUCTO: ";
    EntradaNumerica(cod);

    if(cod<1 || !ProductoManager::existe(cod))
    {
        cout << "EL C�DIGO INGRESADO NO ES V�LIDO" << endl;
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

    cout << "INGRESE CANTIDAD: ";
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
    cout << "INGRESE EL C�DIGO DEL PRODUCTO A QUITAR" << endl;
    EntradaNumerica(cod);
    presupuesto.quitarItem(cod);
    return 1;
}

int Modo7(PresupuestoModel &presupuesto)
{
    cls();
    cout << "�DESEA GUARDAR LOS CAMBIOS?" << endl;
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
                cout << "POR FAVOR, INGRESE UN PLAZO DE VALIDEZ DE ENTRE 1 Y 90 D�AS O -1 PARA REGRESAR" << endl;
                EntradaNumerica(plazo);
            }
            presupuesto.setPlazo(plazo);
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
                cout << "POR FAVOR GUARDE ESTE N�MERO PARA VOLVER A ACCEDER A �L" << endl;
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
    cout << "POR FAVOR INDIQUE EL NUEVO PLAZO (ENTRE 1 Y 90 D�AS) O -1 PARA REGRESAR" << endl;
    cout << "TENGA EN CUENTA QUE LA FECHA DEL PRESUPUESTO DE ACTUALIZAR� AL D�A DE HOY" << endl;
    EntradaNumerica(plazo);

    while(plazo<1 || plazo > 90)
    {
        if(plazo==-1) return 1;
        cout << endl;
        cout << "DEBE INGRESAR UNA CANTIDAD DE D�AS ENTRE 1 Y 90 O -1 PARA REGRESAR" << endl;
        cout << "TENGA EN CUENTA QUE LA FECHA DEL PRESUPUESTO DE ACTUALIZAR� AL D�A DE HOY" << endl;
        EntradaNumerica(plazo);
    }

    presupuesto.recalcular();
    presupuesto.setPlazo(plazo);
    presupuesto.setFecha(Fecha());
    return 1;
}

int Modo11(PresupuestoModel &presupuesto)
{
    cls();
    cout << "�DESEA EMITIR UNA FACTURA A PARTIR DEL PRESUPUESTO N�:  " << presupuesto.getId() << "?" << endl;
    cout << "PRESIONE ENTER PARA CONFIRMAR O ESCAPE PARA REGRESAR" << endl;
    switch(getkey())
    {
        case KEY_ENTER: break;
        case KEY_ESCAPE: return 1;
        default: return 11;
    }

    if(presupuesto.getCantidadItems()==0)
    {
        cout << "NO HAY ITEMS PARA FACTURAR" << endl;
        anykey();
        return 1;
    }

    for(size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        ItemPresupuestoModel item = presupuesto.getItem(i);
        ProductoModel producto = item.getProducto();
        if(producto.getStockDisponible() < item.getCantidad())
        {
            cout << endl << "NO HAY SUFICIENTE STOCK DISPONIBLE DEL PRODUCTO ";
            cout << producto.getCodigoProducto() << " - " << producto.getDescripcionProducto() << endl;
            anykey();
            return 1;
        }
    }

    while(presupuesto.vencido())
    {
        cout << endl;
        cout << "EL PRESUPUESTO SE ENCUENTRA FUERA DE T�RMINO" << endl;
        cout << endl;
        cout << "�DESEA ACTUALIZARLO O CONSERVAR LOS VALORES?" << endl;
        cout << "ESPACIO - ACTUALIZAR    ENTER - CONSERVAR VALORES ACTUALES    ESCAPE - REGRESAR" << endl;
        int key = getkey();
        switch(key)
        {
            case KEY_ESCAPE: return 1;
            case KEY_SPACE: cls(); return Modo9(presupuesto);
        }
        if(key==KEY_ENTER) break;
    }

    ClienteModel cliente;
    while(!ObtenerCliente(cliente))
    {
        cout << "�VOLVER A CARGAR LOS DATOS DEL CLIENTE?" << endl;
        cout << "PRESIONE ENTER PARA REINTENTAR U OTRA TECLA PARA REGRESAR" << endl;
        if(getkey()!=KEY_ENTER) return 1;
    }

    int idFactura = FacturaManager::guardarNuevo(presupuesto, cliente);
    if(idFactura)
    {
        cout << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "                      FACTURA GUARDADA" << endl;
        cout << "ID DE LA FACTURA: " << idFactura << endl;
        cout << "POR FAVOR, GUARDE ESTE N�MERO PARA ACCEDER A ELLA M�S TARDE" << endl;
    }
    else
    {
        cout << "LO SENTIMOS, ALGO SALI� MAL AL REALIZAR LA OPERACI�N" << endl;
    }

    cout << endl << endl << "EL PRESUPUESTO NECESITA VOLVER A CARGARSE" << endl;
    cout << "PRESIONE ENTER PARA GUARDARLO PRIMERO U OTRA TECLA PARA CONTINUAR SIN GUARDAR" << endl;
    if(getkey()==KEY_ENTER)
        PresupuestoManager::sobreescribir(presupuesto);
    PresupuestoManager::cargar(presupuesto.getId(), presupuesto);

    return 1;
}

bool ObtenerCliente(ClienteModel &cliente)
{
    cls();
    showcursor();
    cout << "*** DATOS DEL CLIENTE ***" << endl << endl;

    int DNI=0;
    while(DNI<1)
    {
        cout << "DNI: ";
        EntradaNumerica(DNI);
    }

    if(ClienteManager::existe(DNI))
    {
        if(ClienteManager::cargar(DNI, cliente))
        {
            cout << "NOMBRE: " << cliente.getNombre() << endl;
            cout << "APELLIDO: " << cliente.getApellido() << endl;
            cout << "DIRECCI�N: " << cliente.getDireccion() << endl;
            cout << "TEL�FONO: " << cliente.getTelefono() << endl;

            cout << "PRESIONE ENTER PARA CONFIRMAR U OTRA TECLA PARA REGRESAR" << endl;
            return getkey()==KEY_ENTER;
        }
        else
        {
            cout << "OCURRI� UN PROBLEMA AL CARGAR LOS DATOS DEL CLIENTE" << endl;
            return false;
        }
    }
    else
    {
        cout << endl << "CLIENTE NO ENCONTRADO �DESEA AGREGAR SUS DATOS?" << endl << endl;
        cout << "PRESIONE ENTER PARA REGISTRAR UN NUEVO CLIENTE U OTRA TECLA PARA REGRESAR" << endl << endl;
        if(getkey()!=KEY_ENTER) return false;

        cout << "APELLIDO: ";
        string apellido = EntradaCadena(29);
        cout << "NOMBRE: ";
        string nombre = EntradaCadena(29);
        cout << "DIRECCI�N: ";
        string direccion = EntradaCadena(49);
        cout << "TEL�FONO: ";
        string telefono = EntradaCadena(29);

        cliente = ClienteModel(DNI, nombre, apellido, direccion, telefono);
        if(ClienteManager::guardarNuevo(cliente))
        {
            cout << endl;
            cout << "------------------------------------------------------------------"<<endl;
            cout << "                 CLIENTE AGREGADO";
            anykey();
            return true;
        }
        else
        {
            cout << "HUBO UN PROBLEMA AL GUARDAR LOS DATOS DEL CLIENTE" << endl;
            return false;
        }
    }
}
