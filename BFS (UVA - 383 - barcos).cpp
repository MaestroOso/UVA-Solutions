#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > &grafo, map<string,int> &Id, string inicio, string destino)
{
    vector<bool> marcas(grafo.size(),false);
    queue <int> q;
    queue <int> pos;
    q.push(Id[inicio]);
    pos.push(1);
    marcas[Id[inicio]] = true;

    while(!q.empty())
    {
        int actual = q.front();
        q.pop();
        int nivel = pos.front();
        pos.pop();

        if(actual == Id[destino])
        {
            return nivel;
        }
        for(int i = 0; i<grafo[actual].size(); i++)
        {
            int vecino = grafo[actual][i];
            if(!marcas[vecino])
            {
                marcas[vecino] = true;
                q.push(vecino);
                pos.push(nivel+1);
            }
        }
    }
    return 0;

}

int main()
{
    int casos, x=0;
    cin >> casos;
    while(casos--)
    {
        if(x==0) cout << "SHIPPING ROUTES OUTPUT\n\n";
        x++;
        cout << "DATA SET  " << x << endl << endl;
        int tam, conexiones, prueba,cont=0;
        string aux, aux2;
        cin >> tam >> conexiones >> prueba;
        map<string,int> Id;
        vector<vector<int> > grafo(tam);
        for(int i = 0; i< tam; i++)
        {
            cin>>aux;
            Id[aux] = cont++;
        }

        for(int i = 0; i < conexiones; i++)
        {
            cin>>aux>>aux2;
            grafo[Id[aux]].push_back(Id[aux2]);
            grafo[Id[aux2]].push_back(Id[aux]);
        }

        int tam_carga, camin;
        for(int i = 0; i<prueba; i++){
            cin >> tam_carga >> aux >> aux2;
            camin = bfs(grafo,Id,aux,aux2);
            if(camin==0){
                cout << "NO SHIPMENT POSSIBLE\n";
            } else {
                camin--;
                cout << "$" << camin*100*tam_carga << endl;
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT";
    return 0;
}
