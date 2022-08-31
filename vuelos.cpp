#include<iostream>
#include "vuelos.hpp"
#include "pasajeros.hpp"
using namespace std;

Vuelo::Vuelo()
{

}


Vuelo::Vuelo(int ID, string ciudadOrigen, string ciudadDestino, string fechaSalida, string fechaArribo, int distanciaVuelo, int capacidadPasajeros, int capacidadCarga, int asientosDisponibles)
{
    this->ID = ID;
    this->ciudadOrigen = ciudadOrigen;
    this->ciudadDestino = ciudadDestino;
    this->fechaDeSalida = fechaDeSalida;
    this->fechaDeArribo = fechaArribo;
    this->distanciaDeVuelo = distanciaVuelo;
    this->capacidadDePasajeros = capacidadPasajeros;
    this->capacidadDeCarga = capacidadCarga;
    this->asientosDisponibles = asientosDisponibles;
}

Vuelo::~Vuelo() {
};

void Vuelo::agregarPasajero(Pasajero pasajero)
{
    int id = contPasajeros+1;
    pasajero.setId(id);
    pasajeros.insertar(pasajero);
    cout << "Pasajero agregado" <<endl;
    contPasajeros++;
};

Pasajero* Vuelo::buscarPasajero(Pasajero pasajero)
{
    return pasajeros.buscarNodo(pasajero);
}


void Vuelo::eliminarPasajero(Pasajero pasajero) {
    pasajeros.eliminarNodo(pasajero);
}

void Vuelo::mostrarPasajeros() 
{
    pasajeros.imprimirLista();
}

string Vuelo::getCiudadOrigen() 
{
    return this->ciudadOrigen;
};

string Vuelo::getCiudadDestino()
{
    return this->ciudadDestino;
};

string Vuelo::getfechaSalida()
{
    return this->fechaDeSalida;
};

string Vuelo::getFechaArribo()
{
    return this->fechaDeArribo;
};

int Vuelo::getDistanciaVuelo()
{
    return this->distanciaDeVuelo;
};

int Vuelo::getCapacidadPasajeros()
{
    return this->capacidadDePasajeros;
};

int Vuelo::getCapacidadCarga()
{
    return this->capacidadDeCarga;
};

int Vuelo::getAsientosDisponibles()
{
    return this->asientosDisponibles;
};

int Vuelo::getID() {
    return this->ID;
}

int Vuelo::getContPasajeros()
{
    return this->contPasajeros;
}

/* ---------- SETTERS ----------*/

void Vuelo::setCiudadDestino(string ciudadDestino)
{
    this->ciudadDestino = ciudadDestino;
};

void Vuelo::setCiudadOrigen(string ciudadOrigen)
{
    this->ciudadOrigen = ciudadOrigen;
};

void Vuelo::setFechaSalida(string salida)
{
    this->fechaDeSalida = salida;
};

void Vuelo::setFechaArribo(string arribo)
{
    this->fechaDeArribo = arribo;
};

void Vuelo::setDistanciaVuelo(int distancia)
{
    this->distanciaDeVuelo = distancia;
};

void Vuelo::setCapacidadPasajeros(int pasajeros)
{
    this->capacidadDePasajeros = pasajeros;
};

void Vuelo::setCapacidadCarga(int carga) 
{
    this->capacidadDeCarga = carga;
};

void Vuelo::setAsientosDisponibles(int asientos)
{
    this->asientosDisponibles = asientos;
};

void Vuelo::setId(int idVuelo)
{
    this->ID = idVuelo;
}