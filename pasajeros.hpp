#ifndef PASAJEROS_HPP
#define PASAJEROS_HPP
#include<iostream>
#include<iomanip>
using namespace std;

class Pasajero {
    int ID;
    int idVuelo;
    string nombre;
    string apellido;
    int edad;
    string ciudadOrigen;
    string ciudadDestino;
    string asiento;

public:

    //constructores
    Pasajero();
    Pasajero(int ID, string nombre, string apellido, int edad, string ciudadOrigen, string ciudadDestino, string asiento, int IDVuelo);

    //getters
    string getNombre();
    string getApellido();
    int getEdad();
    string getCiudadOrigen();
    string getCiudadDestino();
    string getAsiento();
    size_t getIdVuelo();
    size_t getIdPasajero();
    size_t getID();
    
    //setters
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setEdad(int edad);
    void setCiudadOrigen(string ciudadOrigen);
    void setCiudadDestino(string ciuidadDestino);
    void setAsiento(string asiento);
    void setIdVuelo(int id);
    void setId(int Id);

    friend ostream &operator<<(ostream &out, const Pasajero &p)
    {
        out << left;
        out << setw(8) << p.ID;
        out << setw(8) << p.nombre;
        out << setw(8) << p.apellido;
        out << setw(8) << p.edad;
        out << setw(8) << p.ciudadOrigen;
        out << setw(8) << p.ciudadDestino;
        out << setw(8) << p.asiento;
        out << setw(8) << p.idVuelo;
        out << endl;
        return out;
    }

    bool operator==(const Pasajero& p){
        return this->ID == p.ID;
    }
};

#endif