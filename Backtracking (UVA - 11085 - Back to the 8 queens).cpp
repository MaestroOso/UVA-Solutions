#include <bits/stdc++.h>
using namespace std;

int arr[8];
int posibilidades[92][8];
int k;

bool valida(){
    for(int i = 0; i<8; i++){
        for(int j = i+1; j<8; j++){
            if(arr[i] == arr[j] || abs(arr[j]-arr[i]) == abs(j-i)){
                return false;
            }
        }
    }
    return true;
}

void movimientos(int p){
    if(p == 8){
        if(valida()){
            for(int i = 0; i<8; i++){
                posibilidades[k][i] = arr[i];
            }
            k++;
        }
    return;
    }

    for(int i = 0; i<8; i++){
        int aux = arr[p];
        arr[p] = i;
        movimientos(p+1);
        arr[p] = aux;
    }
}

int minMov(){
    int minM = 8, act;
    for(int i = 0; i<92; i++){
        act = 0;
        for(int j = 0; j<8; j++){
            if(posibilidades[i][j] != arr[j]){
                act++;
            }
        }
        minM = min(minM,act);
    }
    return minM;
}

int main(){
    int casos = 1; k = 0;
    movimientos(0);
    while(cin >> arr[0]){
        arr[0]--;
        for(int i = 1; i<8; i++){
            cin >> arr[i];
            arr[i]--;
        }
        printf("Case %d: %d\n",casos,minMov());
        casos++;
    }
    return 0;
}
