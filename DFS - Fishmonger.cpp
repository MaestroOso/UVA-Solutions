#include <bits/stdc++.h>
using namespace std;
int minCosto, minTiempo;

void Backtracking (vector<vector<int> >&peajes, vector<vector<int> >&tiempo, vector<bool> visitados, int origen, int costoAct, int tiempoAct, int destino, int tMax)
{
    if(costoAct > minCosto)
    {
        return;
    }

    if(tiempoAct > tMax)
    {
        return;
    }

    if(origen == destino)
    {
        if(costoAct < minCosto)
        {
            minCosto = costoAct;
            minTiempo = tiempoAct;
        }
        else if(costoAct == minCosto)
        {
            if(tiempoAct < minTiempo)
            {
                minCosto = costoAct;
                minTiempo = tiempoAct;
            }
        }
        return;
    }


    for(int i = 0; i<peajes.size(); i++)
    {

        if(i!= origen && !visitados[i])
        {
            visitados[i] = true;
            Backtracking(peajes,tiempo,visitados,i,costoAct + peajes[origen][i], tiempoAct + tiempo[origen][i],destino, tMax);
            visitados[i] = false;
        }
    }
    return;
}

int main()
{
    int vertices, t;
    while(cin>> vertices >> t && vertices)
    {
        vector<vector<int> >peajes(vertices, vector<int>(vertices,0));
        vector<vector<int> >tiempo(vertices, vector<int>(vertices,0));

        //Llenar matriz de peajes
        for(int i = 0; i<vertices; i++)
        {
            for(int j = 0; j<vertices; j++)
            {
                cin >> tiempo[i][j];
            }
        }

        //Llenar matriz de tiempos
        for(int i = 0; i<vertices; i++)
        {
            for(int j = 0; j<vertices; j++)
            {
                cin >> peajes[i][j];
            }
        }

        minCosto = INT_MAX;
        minTiempo = INT_MAX;
        vector<bool> visitados(vertices,false);
        visitados[0] = true;
        Backtracking(peajes,tiempo,visitados,0,0,0,vertices-1,t);
        printf("%d %d\n",minCosto,minTiempo);
    }
    return 0;
}

