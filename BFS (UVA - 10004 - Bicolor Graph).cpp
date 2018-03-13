#include <bits/stdc++.h>
using namespace std;

bool bfs(int o, vector<bool> &visitados, vector<vector<int> > &graph, vector<int> &color)
{
    int act = o;
    color[act] = 0;
    queue<int> cola;
    cola.push(o);
    while(!cola.empty())
    {

        if(visitados[cola.front()]==false)
        {
            act = cola.front();
            for(int i = 0; i<graph[act].size(); i++)
            {
                cola.push(graph[act][i]);
                if(color[graph[act][i]] != -1 && color[graph[act][i]] == color[act]){
                    return false;
                } else{
                    if(color[act] == 0){
                        color[graph[act][i]] = 1;
                    } else {
                        color[graph[act][i]] = 0;
                    }
                }
            }
            visitados[act] = true;
        }
        else
        {
            cola.pop();
        }
    }
    return true;
}
int main()
{
    int vertices, aristas, origen, destino;
    while(cin>> vertices && vertices)
    {
        cin >> aristas;
        vector<vector<int> > graph(vertices);
        vector<bool> visitados(vertices);
        vector<int> color(vertices,-1);
        for(int i = 0; i<aristas; i++){
            cin >> origen >> destino;
            graph[origen].push_back(destino);
            graph[destino].push_back(origen);
        }
        if(bfs(0,visitados,graph,color)){
            cout << "BICOLORABLE.\n";
        } else{
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}
