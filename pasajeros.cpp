#include<iostream>
#include "pasajeros.hpp"
using namespace std;

//Constructor sin parametros
Pasajero::Pasajero() 
{
}

//Constructor con parametros
Pasajero::Pasajero(size_t ID, string nombre, string apellido, size_t edad, string ciudadOrigen, string ciudadDestino, string asiento, size_t IDVuelo)
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
size_t Pasajero::getEdad()
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
void Pasajero::setEdad(size_t edad)
{
    this->edad = edad;
};

void Pasajero::setId(size_t id) 
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

void Pasajero::setIdVuelo(size_t id) {
    this->idVuelo = id;
}