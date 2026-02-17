#include <iostream>
#include <string>
#include "CArbolBinario.h"

using namespace std;

int main() {
    CArbolBinario<string> arbol("Raiz");
    CNodoBinario<string>* raiz = arbol.m_pRoot;

    arbol.insertarIzquierda(raiz, "N1_1");
    arbol.insertarDerecha(raiz, "N1_2");

    // Obtener puntero a N1_1 (el hijo izquierdo) para insertarle hijos
    CNodoBinario<string>* n1 = raiz->m_pLeft; 
    arbol.insertarIzquierda(n1, "N2_1");
    arbol.insertarDerecha(n1, "N2_2");

    // Obtener puntero a N1_2 (el hijo derecho)
    CNodoBinario<string>* n2 = raiz->m_pRight;
    arbol.insertarIzquierda(n2, "N2_3_Solo");

    cout << "Recorrido en PROFUNDIDAD" << endl;
    arbol.recorridoProfundidad(); 

    cout << "\nRecorrido en AMPLITUD" << endl;
    arbol.recorridoAmplitud();

    cout << "\nEliminando N1_1 (con sus hijos N2_1 y N2_2)" << endl;
    if (raiz->m_pLeft == n1) {
        delete raiz->m_pLeft; // El destructor de CNodoBinario borrará N2_1 y N2_2 recursivamente
        raiz->m_pLeft = nullptr;
    }

    cout << "\nAmplitud final" << endl;
    arbol.recorridoAmplitud();

    return 0;
}