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