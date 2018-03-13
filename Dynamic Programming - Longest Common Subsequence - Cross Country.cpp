#include <bits/stdc++.h>
using namespace std;

/**
    http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
    DP
**/
int numeroMaximo(vector<int> &misTarjetas, vector<int> &pretendientes){
    int tamT = misTarjetas.size(), tamP = pretendientes.size();
    vector<vector<int> > matriz(tamT+1, vector<int>(tamP+1, 0));
    for(int i = 0; i<=tamT; i++){
        for(int j = 0; j<=tamP; j++){
            if(i == 0 || j == 0){
                matriz[i][j] = 0;
            }else if(misTarjetas[i-1] == pretendientes[j-1]){
                matriz[i][j] = matriz[i-1][j-1] + 1;
            }else{
                matriz[i][j] = max(matriz[i][j-1], matriz[i-1][j]);
            }
        }
    }
    //cout <<
    return matriz[tamT][tamP];
}

int main(){
    int casos, maximoActual, aux;
    cin >> casos;
    while(casos--){
        maximoActual = 0;
        vector<int> misTarjetas;
        while(cin>>aux && aux){
            misTarjetas.push_back(aux);
        }
        vector<int> pretendientes;
        while(cin >> aux && aux){
            pretendientes.push_back(aux);
            while(cin >> aux && aux){
                pretendientes.push_back(aux);
            }
            maximoActual = max(maximoActual, numeroMaximo(misTarjetas,pretendientes));
            pretendientes.clear();
        }
        printf("%d\n",maximoActual);
    }
    return 0;
}

