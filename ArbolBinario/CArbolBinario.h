#ifndef CARBOLBINARIO_H
#define CARBOLBINARIO_H

#include <iostream>
#include "CNodoBinario.h"
#include "CQueue.h"

template <typename T>
class CArbolBinario {
private:
    void internalProfundidad(CNodoBinario<T>* pNode) {
        if (pNode) {
            std::cout << pNode->valor << " ";
            internalProfundidad(pNode->m_pLeft);
            internalProfundidad(pNode->m_pRight);
        }
    }

public:
    CNodoBinario<T>* m_pRoot;

    CArbolBinario(T valorRaiz) {
        m_pRoot = new CNodoBinario<T>(valorRaiz);
    }

    ~CArbolBinario() {
        if (m_pRoot) delete m_pRoot;
    }

    void insertarIzquierda(CNodoBinario<T>* padre, T valor) {
        if (padre && !padre->m_pLeft) {
            padre->m_pLeft = new CNodoBinario<T>(valor);
        }
    }

    void insertarDerecha(CNodoBinario<T>* padre, T valor) {
        if (padre && !padre->m_pRight) {
            padre->m_pRight = new CNodoBinario<T>(valor);
        }
    }

    void recorridoProfundidad() {
        if (!m_pRoot) return;
        internalProfundidad(m_pRoot);
        std::cout << std::endl;
    }

    void recorridoAmplitud() {
        if (!m_pRoot) return;
        CQueue<CNodoBinario<T>*> cola;
        cola.enqueue(m_pRoot);
        while (!cola.empty()) {
            CNodoBinario<T>* actual = cola.dequeue();
            std::cout << actual->valor << " ";
            if (actual->m_pLeft) cola.enqueue(actual->m_pLeft);
            if (actual->m_pRight) cola.enqueue(actual->m_pRight);
        }
        std::cout << std::endl;
    }
};

#endif