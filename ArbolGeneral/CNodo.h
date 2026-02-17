#ifndef CNODO_H
#define CNODO_H
#include "CArray.h"

template <typename T>
struct CNodo {
    T valor;
    CArray<CNodo<T>*> hijos; 

    CNodo(T v) : valor(v) {}

    ~CNodo() { 
        for (int i = 0; i < hijos.size(); i++) { 
            delete hijos[i]; 
        } 
    }

    void agregarHijo(CNodo<T>* hijo) { 
        hijos.push_back(hijo); 
    }
};

#endif