#ifndef PASAJEROS_HPP
#define PASAJEROS_HPP
#include<iostream>
#include<iomanip>
using namespace std;

class Pasajero {
    size_t ID;
    size_t idVuelo;
    string nombre;
    string apellido;
    size_t edad;
    string ciudadOrigen;
    string ciudadDestino;
    string asiento;

public:

    //constructores
    Pasajero();
    Pasajero(size_t ID, string nombre, string apellido, size_t edad, string ciudadOrigen, string ciudadDestino, string asiento, size_t IDVuelo);

    //getters
    string getNombre();
    string getApellido();
    size_t getEdad();
    string getCiudadOrigen();
    string getCiudadDestino();
    string getAsiento();
    size_t getIdVuelo();
    size_t getIdPasajero();
    size_t getID();
    
    //setters
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setEdad(size_t edad);
    void setCiudadOrigen(string ciudadOrigen);
    void setCiudadDestino(string ciuidadDestino);
    void setAsiento(string asiento);
    void setIdVuelo(size_t id);
    void setId(size_t Id);

    friend ostream &operator<<(ostream &out, const Pasajero &p)
    {
        out << left;
        out << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Apellido" << setw(15) << "Edad" << setw(15) << "CiudadOrigen" << setw(15) << "CiudadDestino" << setw(20) << "Asiento" << setw(20) << "IDVuelo" <<endl;
        out << left;
        out << setw(5) << p.ID;
        out << setw(15) << p.nombre;
        out << setw(15) << p.apellido;
        out << setw(15) << p.edad;
        out << setw(15) << p.ciudadOrigen;
        out << setw(15) << p.ciudadDestino;
        out << setw(20) << p.asiento;
        out << setw(20) << p.idVuelo;
        out <<endl;
        return out;
    }

    bool operator==(const Pasajero& p){
        return this->ID == p.ID;
    }
};

#endif