#include<iostream>
#include "pasajeros.hpp"
using namespace std;

//Constructor sin parametros
Pasajero::Pasajero() 
{
}

//Constructor con parametros
Pasajero::Pasajero(int ID, string nombre, string apellido, int edad, string ciudadOrigen, string ciudadDestino, string asiento, int IDVuelo)
{
    this->ID = ID;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->ciudadOrigen = ciudadOrigen;
    this->ciudadDestino = ciudadDestino;
    this->asiento = asiento;
    this->idVuelo = IDVuelo;
}

//getNombre
string Pasajero::getNombre() 
{
    return this->nombre;
}

//getApellido
string Pasajero::getApellido()
{
    return this->apellido;
}

//getEdad
int Pasajero::getEdad()
{
    return this->edad;
}

//getCiudadOrigen
string Pasajero::getCiudadOrigen()
{
    return this->ciudadOrigen;
}

//getCiudadDestino
string Pasajero::getCiudadDestino()
{
    return this->ciudadDestino;
}

//getAsiento
string Pasajero::getAsiento()
{
    return this->asiento;
}

//getIdVuelo
size_t Pasajero::getIdVuelo()
{
    return this->idVuelo;
}

size_t Pasajero::getID() 
{
    return this->ID;
}

//setNombre
void Pasajero::setNombre(string nombre)
{
    this->nombre = nombre;
}

//setApellido
void Pasajero::setApellido(string apellido)
{
    this->apellido = apellido;
}

//setEdad
void Pasajero::setEdad(int edad)
{
    this->edad = edad;
};

void Pasajero::setId(int id) 
{
    this->ID = id;
};

//setCiudadDestino
void Pasajero::setCiudadDestino(string ciudadDestino)
{
    this->ciudadDestino = ciudadDestino;
};

//setCiudadOrigen
void Pasajero::setCiudadOrigen(string ciudadOrigen)
{
    this->ciudadOrigen = ciudadOrigen;
}

//setAsiento
void Pasajero::setAsiento(string asiento)
{
    this->asiento = asiento;
};

void Pasajero::setIdVuelo(int id) {
    this->idVuelo = id;
}