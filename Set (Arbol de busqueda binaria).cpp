#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

/**
Arbol de Busqueda Binario Balanceado
Mantiene un balanceo, la altura de cada una de las dos ramas
sean las mismas o difieran solo en una
La complejidad de esta busqueda es Log-2 de n
**/
int main(){
    /** Inicializar un Arbol de busqueda binaria **/
    //set<int> miset;
    /**  Insertar un elemento en el arbol **/
    //miset.insert(8);
    /** Eliminar un elemento del arbol**/
    //miset.erase(8);
    /** Iterador es un apuntador a un dato especifico en
    una estructura de datos**/
    //set<int>::iterator it;
    /** El find del iterador busca si el elemento que se esta
    buscando existe. Si existe entonces devuelve un apuntador
    a la posicion de memoria
    De lo contrario devuelve la posicion del set.end()
    que representa una despues de la que existe**/
    //it = miset.find(6);
    //if(it!=miset.end())

    set<string> miset;
    string aux;
    string palabra;
    bool hola = false;
    while (getline(cin, aux)) {
        for (int i = 0; i<aux.length(); i++){
        string aux2 = "";
        hola = false;
        while((aux[i] >= 'a' && aux[i] <= 'z')||(aux[i] >= 'A' && aux[i] <= 'Z')){
            aux2.push_back(tolower(aux[i]));
            i++;
            hola = true;
        }
        if(hola){
        miset.insert(aux2);
        }
    }
    }

    set<string>::iterator it;
    for(it=miset.begin();it!=miset.end();it++){
        cout << *it<< endl;
    }
    return 0;
}
