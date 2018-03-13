#include <bits/stdc++.h>
using namespace std;

const int V_MAX = 101, INF = 1000000000;

/** MaxFlow, Flow, Source, Sink**/
int mf,       f,     s,      t;

/** Matriz de Adyacencia **/
int res[V_MAX][V_MAX];

/** Guarda el arbol de expansión generado por el BFS desde s **/
vector<int> p;


void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    } else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main(){

    /** Casos de prueba  Vertices  Aristas **/
    int casos = 1,       v,        e;
    /** Origen  Destino  Capacidad**/
    int o,      d,       c;

    while(cin >> v && v){

        memset(res,0,sizeof res);

        /** Lista de Adyacencia **/
        vector<vector<int> > AdjList(v);

        cin >> s >> t >> e;
        s--;t--;

        for(int i = 0; i<e; i++){
            cin >> o >> d >> c;
            o--; d--;
            /** Para llevar la cuenta del flujo **/
            res[o][d] += c;
            res[d][o] += c;

            /** Para hacer mas eficiente la busqeuda de los adjacentes (Complejidad menor que en la matriz) **/
            AdjList[o].push_back(d);
            AdjList[d].push_back(o);
        }

        /** Algoritmo de Edmonds-Karp O(V*E^2) **/
        mf = 0;
        /** Mientras haya un camino por el cual se pueda mandar flujo **/
        while(true){
            f = 0;
            /** Bitset para saber cuales se ha visitado **/
            bitset<V_MAX> vis;
            vis[s] = true;

            /** BFS para determinar si hay algun camino y el flujo maximo **/
            queue<int> q;
            q.push(s);
            p.assign(V_MAX, -1);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                /** Si ya llegue al destino **/
                if(u == t){
                    break;
                }
                for(int j = 0; j< AdjList[u].size(); j++){
                    int k = AdjList[u][j];
                    /** Si hay flujo y no lo he visitado **/
                    if(res[u][k] > 0 && !vis[k]){
                        vis[k] = true, q.push(k), p[k] = u;
                    }
                }
            }
            /** **/
            augment(t, INF);
            if(f == 0) break;
            mf += f;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",casos,mf);
        casos++;

    }

    return 0;
}
