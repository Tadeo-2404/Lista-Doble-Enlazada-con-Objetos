#ifndef VUELOS_HPP
#define VUELOS_HPP
#include<iostream>
#include "pasajeros.hpp"
#include "lista.h"
using namespace std;

class Vuelo {
    size_t ID;
    string ciudadOrigen;
    string ciudadDestino;
    string fechaDeSalida;
    string fechaDeArribo;
    int distanciaDeVuelo;
    int capacidadDePasajeros;
    int capacidadDeCarga;
    int asientosDisponibles;
    int contPasajeros = 0;
    ListaDobleLigada<Pasajero> pasajeros;

public:
   Vuelo();
   Vuelo(int ID, string ciudadOrigen, string ciudadDestino, string fechaSalida, string fechaArribo, int distanciaVuelo, int capacidadPasajeros, int capacidadCarga, int asientosDisponibles);
   ~Vuelo();

   void agregarPasajero(Pasajero pasajero);
   void mostrarPasajeros();
   void modificarPasajero(Pasajero pasajero);
   void eliminarPasajero(Pasajero pasajero);
   Pasajero* buscarPasajero(Pasajero pasajero);
    //getters
    string getCiudadOrigen();
    string getCiudadDestino();
    string getfechaSalida();
    string getFechaArribo();
    int getDistanciaVuelo();
    int getCapacidadPasajeros();
    int getCapacidadCarga();
    int getAsientosDisponibles();
    int getID();
    int getContPasajeros();

    //setterss
    void setCiudadOrigen(string ciudadOrigen);
    void setCiudadDestino(string ciuidadDestino);
    void setFechaSalida(string fechaSalida);
    void setFechaArribo(string fechaArribo);
    void setDistanciaVuelo(int distancia);
    void setCapacidadPasajeros(int capacidad);
    void setCapacidadCarga(int carga);
    void setAsientosDisponibles(int asientos);
    void setId(int idVuelo);

    friend ostream &operator<<(ostream &out, const Vuelo &vuelo)
    {
        out << left;
        out << setw(5) << "ID" << setw(15) << "CiudadOrigen" << setw(15) << "CiudadDestino" << setw(15) << "Arribo" << setw(15) << "Salida" << setw(15) << "DistVuelo" << setw(20) << "CapPasajeros" << setw(20) << "CapCarga" << setw(20) << "AsientosDisp" << setw(20) <<endl;
        out << left;
        out << setw(5) << vuelo.ID;
        out << setw(15) << vuelo.ciudadOrigen;
        out << setw(15) << vuelo.ciudadDestino;
        out << setw(15) << vuelo.fechaDeArribo;
        out << setw(15) << vuelo.fechaDeSalida;
        out << setw(15) << vuelo.distanciaDeVuelo;
        out << setw(20) << vuelo.capacidadDePasajeros;
        out << setw(20) << vuelo.capacidadDeCarga;
        out << setw(20) << vuelo.asientosDisponibles;
        out <<endl;
        return out;
    }

    bool operator== (const Vuelo& v) {
         return this->ID == v.ID;
    }
};

#endif