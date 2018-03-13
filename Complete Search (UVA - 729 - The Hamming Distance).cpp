#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos, numBits, distH;
    int aux = 0;
    cin >> casos;
    while(casos--){
        if(aux!=0){
            cout << endl;
        }
        cin >> numBits >> distH;
        vector<int> solucion(numBits,0);
        for(int i = solucion.size()-1; i>=solucion.size()-distH && i>=0; i--){
            solucion[i] = 1;
        }
        do{
            for(int i = 0; i<solucion.size(); i++){
                cout << solucion[i];
            }
            cout << endl;
        }while(next_permutation(solucion.begin(),solucion.end()));
        aux++;
    }
return 0;
}
