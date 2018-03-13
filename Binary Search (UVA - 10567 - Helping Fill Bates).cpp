#include <bits/stdc++.h>
using namespace std;

int origen, destino;

bool respuesta(vector<vector<int> > &letras, string &comp, string &s){

    origen = destino = -1;
    int p, act=-1, ans, lo, hi, mid;

    for(int i = 0; i<comp.size(); i++){
        /**
            Mirar la posicion en el arreglo de letras a la cual corresponde
        **/
        if(comp[i]>='a' && comp[i]<='z'){
            p = comp[i] - 71;
        } else {
            p = comp[i] - 65;
        }

        /**
            Busqueda binaria para saber si se encuentra el caracter
        **/
        lo = 0;
        hi = letras[p].size();
        ans = -1;
        for(int n = 0; n<22; n++){
            mid = (lo+hi)/2;
            if(letras[p][mid] > act){
                hi = mid;
                ans = letras[p][mid];
            } else if(letras[p][mid] <= act){
                lo = mid;
            }
        }

        if(ans == -1){
            return false;
        } else {
            act = ans;
            if(i == 0){
                origen = act;
            }
            if(i == comp.size()-1){
                destino = act;
                return true;
            }
        }
    }
    return true;
}



/**
    Usando el codigo ascii
    Arreglo de posiciones de cada una de las letras
    A --> 0         letra  - 65
    a --> 26        letra - 71
**/

int main(){

    string s, comp;
    cin >> s;

    vector<vector<int> > letras(52);
    for(int i = 0; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z'){
            letras[s[i]-71].push_back(i);
        } else {
            letras[s[i]-65].push_back(i);
        }
    }

    int q;
    cin >> q;

    while(q--){
        cin >> comp;
        if(respuesta(letras,comp,s)){
            printf("Matched %d %d\n", origen,destino);
        } else {
            printf("Not matched\n");
        }
    }
    return 0;
}
