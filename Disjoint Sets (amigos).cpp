#include<bits/stdc++.h>

using namespace std;

vector<int> padres;
vector<int> tamanios;
void iniciar(int n)
{
    padres.assign(n,0);
    tamanios.assign(n,1);
    for(int i = 0; i < n; i++)
    {
        padres[i] = i;
    }
}

int encontrar(int i)
{
    if(padres[i] == i)
    {
        return i;
    }
    else
    {
        return padres[i] = encontrar(padres[i]);
    }
}
bool estan_unidos(int i, int j)
{
    return encontrar(i) == encontrar(j);
}
bool unir(int i, int j)
{
    if(!estan_unidos(i,j))
    {
        int x = encontrar(i);
        int y = encontrar(j);
        padres[y] = x;
        tamanios[x] += tamanios[y];
    }
}

int main()
{
    int casos, amistad, personas;
    cin >> casos;
    for(int i = 0; i<casos; i++){
    map<int, int> id;
    cin >> personas >> amistad;
    iniciar((amistad*2)+1);
    int consecutivo = 1;
    for(int x = 0; x<amistad; x++){
    int p1, p2;
    cin >> p1;
    cin >> p2;
    if(id[p1]==0){
        id[p1] = consecutivo;
        consecutivo++;
    }
    if(id[p2]==0){
        id[p2] = consecutivo;
        consecutivo++;
    }
    unir(id[p1], id[p2]);
    }
    int mayor = 0;
    for(int x=0; x<tamanios.size(); x++){
        if(tamanios[x]>mayor){
            mayor = tamanios[x];
        }
    }
    cout << mayor << endl;
    }
    return 0;
}

