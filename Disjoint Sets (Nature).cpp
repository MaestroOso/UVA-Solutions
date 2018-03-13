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

void resetear()
{
    padres.erase (padres.begin(),padres.begin()+padres.size());
    tamanios.erase (tamanios.begin(),tamanios.begin()+tamanios.size());
}
int tamMax()
{
    int mayor = 0;
    for(int x=0; x<tamanios.size(); x++)
    {
        if(tamanios[x]>mayor)
        {
            mayor = tamanios[x];
        }
    }
    return mayor;
}
int main()
{
    int animales, relaciones;
    string aux, aux2;
    while(cin>>animales>>relaciones && (animales||relaciones))
    {
        map<string, int> id;
        iniciar(animales+1);
        int consecutivo = 1;
        for(int i = 0; i<animales; i++)
        {
            cin >> aux;
            id[aux] = consecutivo;
            consecutivo++;
        }
        for(int i = 0; i<relaciones; i++)
        {
            cin>>aux>>aux2;
            unir(id[aux],id[aux2]);
        }
        cout << tamMax() << endl;
    }
    return 0;
}
