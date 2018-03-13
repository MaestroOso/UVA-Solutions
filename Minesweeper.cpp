#include <bits/stdc++.h>
using namespace std;

int movx[] = {1,1,1,0,-1,-1,-1,0};
int movy[] = {1,0,-1,-1,-1,0,1,1};

void calcular(vector<vector<int> > &tablero, int posx, int posy, int filas, int columnas){
    int nx, ny;
    if(tablero[posx][posy]==-1){
        return;
    }
    for(int i = 0; i<8; i++){
        nx = posx + movx[i];
        ny = posy + movy[i];
        if(nx <0 || ny < 0 || nx >= filas || ny>= columnas){
            continue;
        }
        if(tablero[nx][ny]==-1){
            tablero[posx][posy]++;
        }
    }
}

void imprimirTablero(vector<vector<int> > tablero, int filas, int columnas){
    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            if(tablero[i][j]==-1){
                cout << '*';
            } else {
                cout << tablero[i][j];
            }
        }
        cout << endl;
    }
}

int main(){
    int filas, columnas, casos=1;
    char aux;
    while(cin>>filas>>columnas && (filas || columnas)){
        if(casos>1){
            cout << endl;
        }
        vector<vector<int> >tablero(filas, vector<int>(columnas,-1));
        for(int i = 0; i<filas; i++){
            for(int j = 0; j<columnas; j++){
                cin >> aux;
                if(aux=='*'){
                    tablero[i][j] = -1;
                } else {
                    tablero[i][j] = 0;
                }
            }
        }

        for(int i = 0; i<filas; i++){
            for(int j = 0; j<columnas; j++){
                calcular(tablero,i,j,filas,columnas);
            }
        }

        printf("Field #%d:\n",casos);
        casos++;
        imprimirTablero(tablero,filas,columnas);
    }
    return 0;
}
