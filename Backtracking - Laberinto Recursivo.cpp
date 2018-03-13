#include <bits/stdc++.h>
using namespace std;

int movx[] = {1,0,-1,0};
int movy[] = {0,1,0,-1};

void imprimirMatriz(vector<vector<char> > &matriz){
    for(int i = 0; i<matriz.size(); i++){
        for(int j = 0; j<matriz[i].size(); j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int backtracking(vector<vector<char> > &matriz,int posx,int posy, vector<vector<bool> > &marcas){
    int n = matriz.size(), m = matriz[0].size(), nx, ny;
    if(posx >= n || posy>= m || posx < 0 || posy < 0){
        return 0;
    }
    if(matriz[posx][posy]=='X'){
        return 0;
    }
    if(matriz[posx][posy]=='*'){
        return 1;
    }
    marcas[posx][posy] = true;
    cout << posx << " " << posy << ":\n";
    matriz[posx][posy] = '>';
    system("cls");
    imprimirMatriz(matriz);

    for(int f = 0; f<4; f++){
        nx = posx + movx[f]; ny = posy  + movy[f];
        if(nx < n && ny <m && nx >= 0 && ny >= 0 && marcas[nx][ny] == false){
            if(backtracking(matriz,nx, ny, marcas) == 1){
                return 1;
            }
        }
    }
    matriz[posx][posy] = ' ';
    return 0;
}


int main(){
    int n, m, posx, posy;
    cin >> n >> m;
    cin.ignore();
    vector<vector<char> > matriz(n, vector<char>(m,' '));
    vector<vector<bool> > marcas(n, vector<bool>(m,false));
    string aux;
    for(int i = 0; i<n; i++){
        getline(cin,aux);
        for(int j = 0; j<m; j++){
            matriz[i][j] = aux[j];
            if(matriz[i][j] == '>'){
                posx = i;
                posy = j;
            }
        }
    }
    if(!backtracking(matriz,posx,posy,marcas)){
        cout << "No existe solucion\n";
    }

    return 0;
}
