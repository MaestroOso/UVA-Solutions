#include<bits/stdc++.h>

using namespace std;

int minima_distancia(string palabra){
    int mini = 27, aux=0;
    for(int i = 0; i<palabra.size()-1; i++){
        aux = abs(palabra[i] - palabra[i+1]);
        if(mini>aux){
            mini = aux;
        }
    }
    return mini;
}


int main(){
    string usuario;
    while(cin>>usuario){
        vector<string> combinaciones;
        for(int i = 0; i<11; i++){
            prev_permutation(usuario.begin(),usuario.end());
        }
        for(int i = 0; i<21; i++){
            next_permutation(usuario.begin(),usuario.end());
            combinaciones.push_back(usuario);
        }

        int mini = 0, aux;
        string res = combinaciones[0];
        for(int i = 0; i<combinaciones.size();i++){
            aux = minima_distancia(combinaciones[i]);
            if(aux>mini){
                res = combinaciones[i];
                mini = aux;
            }
        }
        cout << res << mini << endl;

    }

return 0;
}
