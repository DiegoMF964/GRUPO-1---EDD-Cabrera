#include <iostream>
#include <string>
using namespace std;
const int FILAS = 5;
const int COLUMNAS = 5;
void imprimir(string matriz[][COLUMNAS], int filas){
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < COLUMNAS; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    string matriz[FILAS][COLUMNAS]{
        {"Hugo","Paco","Luis","Jesus","Maria"},
        {"Jose","Martha","Ena","Bertha","Lula"},
        {"Putin","Ana","Luisa","Jesusa","Mario"},
        {"Xi","Fi","Fu","Li","Ju"},
        {"Rena","Paca","Leo","Javier","Bruno"}
    };

    imprimir(matriz, FILAS);
    
    cout << "\nContorno" << endl;
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if(i == 0 || j == 0 || j == COLUMNAS - 1 || i == FILAS - 1){
                cout << matriz[i][j] << " ";
            } else {
                cout << "     "; 
            }
        }
        cout << "\n";
    }

    return 0;
}