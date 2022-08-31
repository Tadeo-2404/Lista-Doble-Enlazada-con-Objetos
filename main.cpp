#include <iostream>
#include "pasajeros.cpp"
#include "vuelos.cpp"
#include "lista.h"
using namespace std;

Vuelo capturarVuelo()
{
    Vuelo vuelo;

    string temp;
    int numTemp;

    cout << "Ciudad de Origen: ";
    getline(cin, temp);
    vuelo.setCiudadOrigen(temp);

    cout << "Ciudad de Destino: ";
    getline(cin, temp);
    vuelo.setCiudadDestino(temp);

    cout << "Fecha de Salida: ";
    getline(cin, temp);
    vuelo.setFechaSalida(temp);

    cout << "Fecha de Arribo: ";
    getline(cin, temp);
    vuelo.setFechaArribo(temp);

    cout << "Distancia De Vuelo: ";
    cin >> numTemp;
    vuelo.setDistanciaVuelo(numTemp);

    cout << "Capacidad de Pasajeros: ";
    cin >> numTemp;
    vuelo.setCapacidadPasajeros(numTemp);

    cout << "Capacidad de Carga: ";
    cin >> numTemp;
    vuelo.setCapacidadCarga(numTemp);

    return vuelo;
}

Pasajero capturaPasajero()
{
    Pasajero pasajero;
    string temp;
    int edad;
    int ID;
    size_t idVuelo;
    cout << "Nombre: ";
    getline(cin, temp);
    pasajero.setNombre(temp);

    cout << "Apellido: ";
    getline(cin, temp);
    pasajero.setApellido(temp);

    cout << "Edad: ";
    cin >> edad;
    cin.ignore();
    pasajero.setEdad(edad);

    cout << "Asiento: ";
    getline(cin, temp);
    pasajero.setAsiento(temp);

    pasajero.setId(ID++);
    return pasajero;
}

int main()
{
    int opc, IDVuelo = 0;
    cout << "Bienvenido al Aeropuerto Guadalajara" << endl;

    ListaDobleLigada<Vuelo> Terminal;

    do
    {
        cout << "1) Capturar Pasajeros" << endl;
        cout << "2) Modificar Pasajeros" << endl;
        cout << "3) Mostrar Pasajeros" << endl;
        cout << "4) Capturar Vuelos" << endl;
        cout << "5) Modificar Vuelos" << endl;
        cout << "6) Mostrar Vuelos" << endl;
        cout << "7) Eliminar Pasajeros" << endl;
        cout << "8) Eliminar Vuelos" << endl;
        cout << "0) Salir" << endl;
        cout << "Seleccione una opcion" << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            int id, valor;
            Vuelo vueloAux;
            cout << "Capturar Pasajeros" << endl;
            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();
            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            cin.ignore();
            vueloAux.setId(id);
            Vuelo *vuelo = Terminal.buscarNodo(vueloAux);
            Pasajero pasajero = capturaPasajero();
            pasajero.setCiudadOrigen(vuelo->getCiudadOrigen());
            pasajero.setCiudadDestino(vuelo->getCiudadDestino());
            pasajero.setIdVuelo(vuelo->getID());
            vuelo->setAsientosDisponibles(vuelo->getAsientosDisponibles() - 1);
            vuelo->agregarPasajero(pasajero);
            break;
        }

        case 2:
        {
            int id, option, valorInt, ID;
            cout << "Modificar Pasajeros" << endl;
            Vuelo *vuelo;
            Vuelo vueloAux;
            Pasajero pasajeroAux;
            string valor;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();

            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            vuelo->setId(id);
            vuelo = Terminal.buscarNodo(vueloAux);

            if (vuelo == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            if (vuelo->getContPasajeros() == 0)
            {
                cout << "Error: no hay pasajeros disponibles" << endl;
                break;
            }

            vuelo->mostrarPasajeros();
            cout << "Seleccione un ID de Pasajero" << endl;
            cin >> ID;
            pasajeroAux.setId(ID);
            Pasajero *pasajero = vuelo->buscarPasajero(pasajeroAux);

            do
            {

                cout << "MODIFICAR PASAJERO" << endl;
                cout << "1) Modificar Nombre" << endl;
                cout << "2) Modificar Apellido" << endl;
                cout << "3) Modificar edad" << endl;
                cout << "4) Modificar asiento" << endl;
                cin >> option;
                cin.ignore();

                switch (option)
                {
                case 1:
                {
                    cout << "Nombre" << endl;
                    cout << "Ingresa nuevo valor" << endl;
                    getline(cin, valor);
                    pasajero->setNombre(valor);
                    cout << "Se ha actualizado la informacion" << endl;
                    break;
                }

                case 2:
                {
                    cout << "Apellido" << endl;
                    cout << "Ingresa nuevo valor" << endl;
                    getline(cin, valor);
                    pasajero->setApellido(valor);
                    cout << "Se ha actualizado la informacion" << endl;
                    break;
                }

                case 3:
                {
                    cout << "Edad" << endl;
                    cout << "Ingresa nuevo valor" << endl;
                    cin >> valorInt;
                    cin.ignore();
                    pasajero->setEdad(valorInt);
                    cout << "Se ha actualizado la informacion" << endl;
                    break;
                }

                case 4:
                {
                    cout << "Asiento" << endl;
                    cout << "Ingresa nuevo valor" << endl;
                    getline(cin, valor);
                    pasajero->setAsiento(valor);
                    cout << "Se ha actualizado la informacion" << endl;
                    break;
                }

                default:
                    cout << "Opcion no valida" << endl;
                    break;
                }
            } while (option > 4 | option == 0);
                break;
        }

        case 3:
        {
            cout << "Mostrar Pasajeros" << endl;
            int id;
            Vuelo vueloAux;
            Vuelo *vuelo;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();
            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            vueloAux.setId(id);
            vuelo = Terminal.buscarNodo(vueloAux);

            if (vuelo == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            if (vuelo->getContPasajeros() == 0)
            {
                cout << "Error: no hay pasajeros disponibles" << endl;
                break;
            }

            vuelo->mostrarPasajeros();
            break;
        }

        case 4:
        {
            cout << "Capturar Vuelos" << endl;
            Vuelo vuelo = capturarVuelo();
            vuelo.setAsientosDisponibles(vuelo.getCapacidadPasajeros());
            vuelo.setId(IDVuelo++);
            Terminal.insertar(vuelo);
            Terminal.contVuelos++;
            break;
        }

        case 5:
        {
            int id, opc, valorInt;
            cout << "Modificar Vuelos" << endl;
            Vuelo vueloAux;
            string valor;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();

            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            vueloAux.setId(id);
            Vuelo *vuelo = Terminal.buscarNodo(vueloAux);
            if (vuelo == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            cout << "MODIFICAR VUELO" << endl;
            cout << "1) Modificar ciudadOrigen" << endl;
            cout << "2) Modificar ciudadDestino" << endl;
            cout << "3) Modificar fechaSalida" << endl;
            cout << "4) Modificar fechaArribo" << endl;
            cout << "5) Modificar distancia de Vuelo" << endl;
            cout << "6) Modificar asientos Disponibles" << endl;
            cout << "7) Modificar capacidad de Carga" << endl;
            cin >> opc;
            cin.ignore();

            switch (opc)
            {
            case 1:
            {
                cout << "Ciudad Origen" << endl;
                cout << "Ingresa nuevo valor" << endl;
                getline(cin, valor);
                vuelo->setCiudadOrigen(valor);
                vuelo->actualizarValorPasajeros(1, valor);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 2:
            {
                cout << "Ciudad Destino" << endl;
                cout << "Ingresa nuevo valor" << endl;
                getline(cin, valor);
                vuelo->setCiudadDestino(valor);
                vuelo->actualizarValorPasajeros(2, valor);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 3:
            {
                cout << "Fecha Salida" << endl;
                cout << "Ingresa nuevo valor" << endl;
                getline(cin, valor);
                vuelo->setFechaSalida(valor);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 4:
            {
                cout << "Fecha Arribo" << endl;
                cout << "Ingresa nuevo valor" << endl;
                getline(cin, valor);
                vuelo->setFechaArribo(valor);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 5:
            {
                cout << "Distancia de Vuelo" << endl;
                cout << "Ingresa nuevo valor" << endl;
                cin >> valorInt;
                vuelo->setDistanciaVuelo(valorInt);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 6:
            {
                cout << "Asientos Disponibles" << endl;
                cout << "Ingresa nuevo valor" << endl;
                cin >> valorInt;
                vuelo->setAsientosDisponibles(valorInt);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            case 7:
            {
                cout << "Capacidad de Carga" << endl;
                cout << "Ingresa nuevo valor" << endl;
                cin >> valorInt;
                vuelo->setCapacidadCarga(valorInt);
                cout << "Se ha actualizado la informacion" << endl;
                break;
            }

            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        }

        case 6:
        {

            cout << "Mostrar Vuelos" << endl;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();
            break;
        }

        case 7:
        {
            cout << "ELIMINAR PASAJERO" << endl;
            int id, opc, valorInt, ID;
            Vuelo vueloAux;
            Pasajero pasajeroAux;
            string valor;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            vueloAux.setId(id);
            Vuelo *vuelo = Terminal.buscarNodo(vueloAux);

            if (vuelo == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            if (vuelo->getContPasajeros() == 0)
            {
                cout << "Error: no hay pasajeros disponibles" << endl;
                break;
            }

            vuelo->mostrarPasajeros();
            cout << "Seleccione un ID de Pasajero" << endl;
            cin >> ID;
            pasajeroAux.setId(ID);
            Pasajero *pasajero = vuelo->buscarPasajero(pasajeroAux);

            if (pasajero == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            vuelo->eliminarPasajero(*pasajero);
            cout << "Pasajero con el ID " << pasajero->getID() << " eliminado correctamente" << endl;
            break;
        }

        case 8:
        {
            int id;
            cout << "ELIMINAR VUELO" << endl;
            Vuelo *vuelo;
            Vuelo vueloAux;

            if (Terminal.getContVuelos() == 0)
            {
                cout << "Error: no hay vuelos disponibles" << endl;
                break;
            }

            Terminal.imprimirLista();
            cout << "Seleccione un ID de Vuelo" << endl;
            cin >> id;
            cin.ignore();

            vueloAux.setId(id);
            vuelo = Terminal.buscarNodo(vueloAux);

            if (vuelo == nullptr)
            {
                cout << "Error: ID no valido" << endl;
                break;
            }

            Terminal.eliminarNodo(*vuelo);
            cout << "Vuelo con el ID " << vuelo->getID() << " eliminado correctamente" << endl;
            break;
        }

        default:
            cout << "Opcion no valida intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);

    return 0;
}