#include <iostream>
#include <string>

#include <stdexcept> 
using namespace std;

class ArregloUnidimensional{
private:
    int tamano;
    static const int CAPACIDAD_MAXIMA=10;
    string elementos[CAPACIDAD_MAXIMA];
public:
    ArregloUnidimensional(){
    this->tamano=0;
}
    void insertarNombre(int indice, string nombre){
        if(tamano==CAPACIDAD_MAXIMA){
            throw runtime_error("Arreglo lleno");
        }
        if(indice<0||indice>tamano){
            throw out_of_range("Indice fuera del rango: "+to_string(indice));
        }
        if(nombre.empty() || nombre.find_first_not_of(' ') == string::npos){return;}

        for(int i=tamano;i>indice;i--){elementos[i]=elementos[i-1];}
        elementos[indice]=nombre;
        tamano++;
    }
    string eliminar( int indice ){
        if(indice<0||indice>=tamano){
            throw out_of_range("Indice fuera del rango "+to_string(indice));
        }
        string eliminar = elementos[indice];
        for(int i = indice; i<tamano-1;i++){
            elementos[i]=elementos[i+1];
        }
        elementos[tamano-1]="";
        tamano--;
        return eliminar;
    }
    string obtener(int indice){
        if(indice<0||indice>tamano){
            throw out_of_range("Indice fuera del rango: "+to_string(indice));
        }
    return elementos[indice];
    }
    int getTamano(){
        return tamano;
    }
    bool estaLLeno(){
        return tamano==CAPACIDAD_MAXIMA;
    }

    void imprimir(){
        if(tamano==0){
            cout<<"El arreglo esta vacio";
            return;
        }
        cout<<"[";
        for(int i =0;i<tamano;i++){
        cout<<elementos[i];
        if(i<tamano-1){cout<<",";}}
        cout<<"]"<<endl;

    }
};
int main() {
    ArregloUnidimensional arr;
    try {
        arr.insertarNombre(0, "Hugo");
        arr.insertarNombre(1, "Paco");
        arr.insertarNombre(1, "Luis"); 
        arr.insertarNombre(2, "Ana");
        arr.insertarNombre(3, "Javier");
        arr.insertarNombre(4, "Maria");
        arr.insertarNombre(5, "Ena");
        arr.insertarNombre(6, "Martha");
        arr.insertarNombre(7, "Bertha");
        arr.insertarNombre(8, "Gaby");
        cout << "Arreglo Lleno" << endl;
        arr.imprimir();
        try {
            arr.insertarNombre(9, "Donald Trompas");
        } catch (const exception& e) {
            cout << "\n Error capturado: " << e.what() << endl;
        }
        string eliminado = arr.eliminar(0);
        cout << "\nEliminado: " << eliminado << endl;
        arr.imprimir();
        arr.eliminar(4);
        cout << "Despues de eliminar indice 4" << endl;
        arr.imprimir();
    } catch (const exception& e) {
        cout << "Error general: " << e.what() << endl;
    }
    return 0;
}