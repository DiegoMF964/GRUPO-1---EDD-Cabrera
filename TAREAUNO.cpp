#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ArregloUnidimensional {
private:
    static const int CAPACIDAD_MAXIMA = 10;
    string elementos[CAPACIDAD_MAXIMA];
    int tamano;

    // Función auxiliar para limpiar espacios (trim)
    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first) return "";
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

public:
    // Constructor
    ArregloUnidimensional() {
        tamano = 0;
    }

    void insertar(int indice, string nombre) {
        if (tamano == CAPACIDAD_MAXIMA)
            throw logic_error("Arreglo Lleno");
        
        if (indice < 0 || indice > tamano)
            throw out_of_range("Indice fuera de rango");

        string nombreLimpio = trim(nombre);
        if (nombreLimpio.empty()) return;

        // Desplazar elementos hacia la derecha
        for (int i = tamano; i > indice; i--) {
            elementos[i] = elementos[i - 1];
        }

        elementos[indice] = nombreLimpio;
        tamano++;
    }

    string eliminar(int indice) {
        if (indice < 0 || indice >= tamano)
            throw out_of_range("Indice fuera de rango");

        string nombreEliminado = elementos[indice];

        // Desplazar elementos hacia la izquierda
        for (int i = indice; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }

        elementos[tamano - 1] = ""; // Limpiar rastro
        tamano--;
        return nombreEliminado;
    }

    string obtener(int indice) {
        if (indice < 0 || indice >= tamano)
            throw out_of_range("Indice fuera de rango");
        return elementos[indice];
    }

    int getTamano() {
        return tamano;
    }

    bool estaLleno() {
        return tamano == CAPACIDAD_MAXIMA;
    }

    void imprimir() {
        if (tamano == 0) {
            cout << "[] (arreglo vacio)" << endl;
            return;
        }
        cout << "[";
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Ejemplo de uso (Main)
int main() {
    try {
        ArregloUnidimensional lista;
        
        lista.insertar(0, "Hugo");
        lista.insertar(1, "Paco");
        lista.insertar(2, "Luis");
        
        cout << "Lista inicial: ";
        lista.imprimir();
        
        lista.insertar(1, "Donald");
        cout << "Tras insertar a Donald en indice 1: ";
        lista.imprimir();
        
        string eliminado = lista.eliminar(2);
        cout << "Eliminado: " << eliminado << endl;
        cout << "Lista final: ";
        lista.imprimir();
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}