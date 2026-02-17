#ifndef CARBOLGENERAL_H
#define CARBOLGENERAL_H

#include <iostream>
#include "CNodo.h"
#include "CQueue.h"

template <typename T>
class CArbolGeneral {
private:
    void internalProfundidad(CNodo<T>* pNode) {
        if (pNode) {
            std::cout << pNode->valor << std::endl; 
            for (int i = 0; i < pNode->hijos.size(); i++) {
                internalProfundidad(pNode->hijos[i]); 
            }
        }
    }

public:
    CNodo<T>* m_pRoot;

    CArbolGeneral(T valorRaiz) {
        m_pRoot = new CNodo<T>(valorRaiz);
    }

    ~CArbolGeneral() {
        if (m_pRoot) delete m_pRoot;
    }

    void insertar(CNodo<T>* nodoPadre, T valorHijo) {
        if (nodoPadre) {
            CNodo<T>* hijo = new CNodo<T>(valorHijo);
            nodoPadre->agregarHijo(hijo);
        }
    }

    void eliminar(CNodo<T>* nodoPadre, CNodo<T>* nodoHijo) {
        if (!nodoPadre || !nodoHijo) return;
        if (nodoPadre->hijos.removeByValue(nodoHijo)) {
            delete nodoHijo; 
        }
    }

    void recorridoProfundidad() {
        if (!m_pRoot) return;
        internalProfundidad(m_pRoot);
    }

    void recorridoAmplitud() {
        if (!m_pRoot) return;
        CQueue<CNodo<T>*> cola; 
        cola.enqueue(m_pRoot);
        while (!cola.empty()) {
            CNodo<T>* actual = cola.dequeue(); 
            std::cout << actual->valor << std::endl;
            for (int i = 0; i < actual->hijos.size(); i++) {
                cola.enqueue(actual->hijos[i]);
            }
        }
    }
};
#endif