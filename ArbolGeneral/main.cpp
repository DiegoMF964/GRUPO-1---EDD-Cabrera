#include <iostream>
#include <string>
#include "CArbolGeneral.h"

using namespace std;

int main() {
    CArbolGeneral<string> arbol("Raiz");
    CNodo<string>* raiz = arbol.m_pRoot;

    arbol.insertar(raiz, "N1_1");
    arbol.insertar(raiz, "N1_2");
    arbol.insertar(raiz, "N1_3");

    CNodo<string>* n1 = raiz->hijos[0]; 
    arbol.insertar(n1, "N2_1");
    arbol.insertar(n1, "N2_2");

    CNodo<string>* n2 = raiz->hijos[1];
    arbol.insertar(n2, "N2_3_Solo");

    cout << "Recorrido en PROFUNDIDAD" << endl;
    arbol.recorridoProfundidad(); 

    cout << "\nRecorrido en AMPLITUD" << endl;
    arbol.recorridoAmplitud();

    cout << "\nEliminando N1_1 (con sus hijos N2_1 y N2_2)" << endl;
    arbol.eliminar(raiz, n1);

    cout << "\nAmplitud final" << endl;
    arbol.recorridoAmplitud();

    return 0;
}