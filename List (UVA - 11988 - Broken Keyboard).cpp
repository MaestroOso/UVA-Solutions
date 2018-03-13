#include <bits/stdc++.h>
using namespace std;
int main(){
    string linea;
    while(getline(cin,linea)){
        list<char> BeijuText;
        /**Opcion 1 --> Insertar al final
           Opcion 2 --> Insertar al inicio
        **/
        int opcion = 1;
        int posicionFrente = 0;
        list<char>::iterator iterador;
        for(int i = 0; i<linea.size(); i++){
            iterador = BeijuText.begin();
            if(linea[i]=='['){
                opcion = 2;
                posicionFrente = 0;
            } else if (linea[i] == ']'){
                opcion = 1;
            } else if (opcion==1){
                BeijuText.push_back(linea[i]);
            } else {
                if(posicionFrente == 0){
                BeijuText.push_front(linea[i]);
                posicionFrente++;
                } else {
                for(int i = 0; i<posicionFrente; i++){
                    iterador++;
                }
                BeijuText.insert(iterador, linea[i]);
                posicionFrente++;
                }
            }
        }
        for(list<char>::iterator it = BeijuText.begin(); it!=BeijuText.end(); it++){
            cout << *it;
        }
        cout << endl;
    }
return 0;
}
