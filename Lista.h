#ifndef LISTA_DOBLE_LIGADA_H
#define LISTA_DOBLE_LIGADA_H

#include <iostream>
using namespace std;

template <class T>
class ListaDobleLigada
{
public:
    ListaDobleLigada(); //CONSTRUCTOR
    ~ListaDobleLigada(); //DESTRUCTOR
    bool empty();
    void insertar(T &dato);
    T* buscarNodo(T &dato);
    T& modificarNodo(T &dato);
    void eliminarNodo(T &dato);
    void imprimirLista();
	int getContVuelos() {
		return this->contVuelos;
	};
	void setContVuelos(int cont) {
		this->contVuelos = cont;
	}
	int contVuelos = 0;
    size_t size();

private:
    struct Nodo {
        T dato;
        Nodo *siguiente;
        Nodo *anterior;
        Nodo() {};
        Nodo(const T &dato, Nodo *siguiente = nullptr, Nodo *anterior = nullptr)
        : dato(dato), siguiente(siguiente), anterior(anterior) {}
    };

    Nodo *primero;
    Nodo *ultimo;
    size_t cont;
};

template <class T>
ListaDobleLigada<T>::ListaDobleLigada()
{
    primero = nullptr;
    ultimo = nullptr;
    cont = 0;
}

template <class T>
ListaDobleLigada<T>::~ListaDobleLigada()
{
	Nodo *actual = primero;
	Nodo *siguiente;

	while (actual != NULL)
	{
		siguiente = actual->siguiente;
		delete actual;
		actual = siguiente;
	}
}

template <class T>
bool ListaDobleLigada<T>::empty()
{
    return cont == 0;
}

template <class T>
void ListaDobleLigada<T>::insertar(T &dato)
{
    Nodo *nodo = new Nodo(dato, primero);
    if (cont == 0) { // empty()
        primero = nodo;
        ultimo = nodo;
    } else {
        primero->anterior = nodo;
        primero = nodo;
    }
    cont++;
};

template<class T>
T* ListaDobleLigada<T>::buscarNodo(T& nodoBuscado){
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoBuscado){
				return &actual->dato;
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "Registro no Encontrado" <<endl;
			return nullptr;
		}
		
	}else{
		cout << "La listas se encuentra Vacia" <<endl;
		return nullptr;
	}

	return nullptr;
};

template<class T>
T& ListaDobleLigada<T>::modificarNodo(T& nodoModificado){
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoModificado){
				encontrado = true;
				return actual->dato;
			}
			
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "Registro no Encontrado" <<endl;
		}
		
	}else{
		cout << "La listas se encuentra Vacia" <<endl;
	}
}

template<class T>
void ListaDobleLigada<T>::eliminarNodo(T& nodoBuscado){
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	bool encontrado = false;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato.getID() == nodoBuscado.getID()){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->anterior = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				
				cout << "Registro eliminado" <<endl;
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "Registro no Encontrado" <<endl;
		}
		
	}else{
		cout << "La listas se encuentra Vacia" <<endl;
	}
}

template <class T>
void ListaDobleLigada<T>::imprimirLista(){
	Nodo* actual = new Nodo();
	actual = primero;
	if(primero!=NULL){
		
		while(actual!=NULL){
			cout << actual->dato; 
			actual = actual->siguiente;
		}
		
	}else{
		cout << "La listas se encuentra Vacia";
	}
}


template <class T>
size_t ListaDobleLigada<T>::size()
{
    return cont;
}

#endif