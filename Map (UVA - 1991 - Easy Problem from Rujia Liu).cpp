#include<bits/stdc++.h>

using namespace std;
int main(){
    int num, preguntas, aux, queso, posicion;
    while(cin >> num >> preguntas){
        map<int,vector<int> > numeros;
        for(int i = 0; i<num; i++){
            cin >> aux;
            numeros[aux].push_back(i+1);
        }

        for(int i = 0; i<preguntas; i++){
            cin >> posicion >> queso;
            if(numeros[queso].size()==0){
                cout << 0 << endl;
            }else if(posicion<=numeros[queso].size()){
                cout << numeros[queso][posicion-1] << endl;
            } else {
                cout <<0 << endl;
            }
        }
    }
return 0;
}
