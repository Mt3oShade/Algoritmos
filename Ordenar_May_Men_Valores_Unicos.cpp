#include <iostream>
#define EXT 100
using namespace std;

int main(){
    int V[EXT], Cant;
    
    int DetNValores(int i, int f);
    bool CompararRep(int V[], int Valor, int n);
    void IngresarValores(int V[], int n);
    void OrdenarAscd(int V[],  int n);

    Cant = DetNValores(1, EXT);
    IngresarValores(V, Cant);
    OrdenarAscd(V, Cant); 

    for(int i = 0; i < Cant; i++){
        cout << "[" << i + 1 << "]: " << V[i] << endl;
    }
}

int DetNValores(int i, int f){
    int n;
    do{
        cout << "Ingrese cuantos valores desea ingresar (" << i << " ... " << f << "): "; cin >> n;
        if((n < i) || (n > f)){
            cout << "Ingrese un valor válido entre "<< i << " y " << f << endl << endl; 
        }
    }while((n < i) || (n > f)); 
    return n;
}

bool CompararRep(int V[], int Valor, int n){
    int aux = -1;
    for(int i = 0; i < n; i++){
        if(Valor == V[i]){
            cout << "Repeticion Detectada. Ingrese otro vector." << endl << endl;
            return true;
        }
    }
    return false;
}

void IngresarValores(int V[], int n){
    for(int i = 0; i < n; i++){
        do{
            cout << "[" << i + 1 << "]: ";  cin >> V[i];
        } while (CompararRep(V, V[i], i - 1));
    }
}

void OrdenarAscd(int V[],  int n){
    for (int i = 1; i < n; ++i) {
        int llave = V[i];
        int j = i - 1;

        while (j >= 0 && V[j] > llave) {
            V[j + 1] = V[j];
            j = j - 1;
        }

        V[j + 1] = llave;
    }
}
