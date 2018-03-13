#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int contarTrue(vector<vector<bool> >&posUsadas){
    int cont = 0;
    for(int i = 0; i<posUsadas.size(); i++){
        for(int j = 0; j<posUsadas[i].size(); j++){
            if(posUsadas[i][j]){
                cont++;
            }
        }
    }
    return cont;
}

bool posValida(ii destino)
{
    if(destino.first >= 7 || destino.second >= 8)
    {
        return false;
    }
    return true;
}

ii pos(int num)
{
    return ii(num/8, num%8);
}

void backtracking(int posicion, map<ii, bool> &fichas, vector<vector<int> > &tablero, int &resultado, vector<vector<bool> >&posUsadas)
{

    if(contarTrue(posUsadas) == 56){
        resultado++;
        return;
    }

    if(posicion == 55)
    {
        return;
    }
    ii coordenada = pos(posicion);

    if(posUsadas[coordenada.first][coordenada.second] == true)
    {
        backtracking(posicion+1, fichas, tablero, resultado, posUsadas);
    }
    else
    {
        if(posValida(ii(coordenada.first + 1, coordenada.second)))
        {
            if(posUsadas[coordenada.first + 1][coordenada.second] == false)
            {
                int m = min(tablero[coordenada.first][coordenada.second], tablero[coordenada.first+1][coordenada.second]);
                int n = max(tablero[coordenada.first][coordenada.second], tablero[coordenada.first+1][coordenada.second]);
                if(fichas[ii(m,n)] == false)
                {
                    posUsadas[coordenada.first][coordenada.second] = true;
                    posUsadas[coordenada.first+1][coordenada.second] = true;
                    fichas[ii(m,n)] = true;

                    backtracking(posicion+1,fichas,tablero,resultado,posUsadas);

                    fichas[ii(m,n)] = false;
                    posUsadas[coordenada.first][coordenada.second] = false;
                    posUsadas[coordenada.first+1][coordenada.second] = false;
                }
            }
        }

        if(posValida(ii(coordenada.first, coordenada.second + 1)))
        {
            if(posUsadas[coordenada.first][coordenada.second + 1] == false)
            {
                int m = min(tablero[coordenada.first][coordenada.second], tablero[coordenada.first][coordenada.second+1]);
                int n = max(tablero[coordenada.first][coordenada.second], tablero[coordenada.first][coordenada.second+1]);
                if(fichas[ii(m,n)] == false)
                {
                    posUsadas[coordenada.first][coordenada.second] = true;
                    posUsadas[coordenada.first][coordenada.second + 1] = true;
                    fichas[ii(m,n)] = true;

                    backtracking(posicion+1,fichas,tablero,resultado,posUsadas);

                    fichas[ii(m,n)] = false;
                    posUsadas[coordenada.first][coordenada.second] = false;
                    posUsadas[coordenada.first][coordenada.second+1] = false;
                }
            }
        }
    }
    return;
}

int main()
{
    int casos;
    cin >> casos;
    while(casos--)
    {
        map<ii, bool> fichas;
        for(int i = 0; i<=6; i++)
        {
            for(int j = i; j<=6; j++)
            {
                fichas[ii(i,j)] = false;
            }
        }
        /** Crear tablero y llenarlo**/
        vector<vector<int> >tablero(7, vector<int>(8,0));
        vector<vector<bool> >posUsadas(7, vector<bool>(8,false));
        for(int i = 0; i<tablero.size(); i++)
        {
            for(int j = 0; j<tablero[i].size(); j++)
            {
                cin >> tablero[i][j];
            }
        }

        int resultado = 0;
        backtracking(0,fichas,tablero,resultado,posUsadas);
        cout << resultado << endl;
    }
    return 0;
}

