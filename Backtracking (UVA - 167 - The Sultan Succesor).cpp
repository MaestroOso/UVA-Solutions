#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > damas;

bool posCorrecta(vector<int> &tablero, int fila, int col){
    for(int anterior = 0; anterior<col; anterior++){
        if(tablero[anterior]== fila || (abs(tablero[anterior]-fila) == abs(anterior-col))){
            return false;
        }
    }
    return true;
}

void backtracking(vector<int> &tablero, int filaD, int columnaD, int variableQueRecorre){
    if(variableQueRecorre==8 && tablero[columnaD] == filaD){
        damas.push_back(tablero);
    }
    for(int r = 0; r<8; r++){
        if(posCorrecta(tablero,r,variableQueRecorre)){
            tablero[variableQueRecorre] = r;
            backtracking(tablero,filaD,columnaD,variableQueRecorre+1);
        }
    }
}

int main(){
    vector<int> tablero(8,0);
    for(int i = 0; i<8; i++){
    backtracking(tablero,i,0,0);
    }
    int casos;
    cin >> casos;
    while(casos--){
        int arr[8][8] = {0};
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                cin >> arr[i][j];
            }
        }
        int sumaMax = 0, sumaParcial=0;
        for(int i = 0; i<damas.size(); i++){
            sumaParcial = 0;
            for(int j = 0; j<8; j++){
                sumaParcial+= arr[j][damas[i][j]];
            }
            sumaMax = max(sumaMax,sumaParcial);
        }
        printf("%5d\n",sumaMax);
    }
return 0;}
