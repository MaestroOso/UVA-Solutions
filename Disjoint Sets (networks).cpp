#include<bits/stdc++.h>

using namespace std;

vector<int> padres;
void iniciar(int n)
{
    padres.assign(n,0);
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
    }
}
int main()
{
    int casos;
    cin>>casos;
    cin.ignore();
    string basura;
    getline(cin,basura);
    for(int c = 0; c < casos; c++)
    {
        if(c >0)
        {
            cout<<endl;
        }
        int tam;
        cin>>tam;
        cin.ignore();
        iniciar(tam+1);
        string linea;
        int correctos, incorrectos;
        correctos = incorrectos = 0;
        while(getline(cin,linea) && linea != "")
        {
            stringstream ss(linea);
            char c;
            int i, j;
            ss>>c>>i>>j;
            if(c == 'c')
            {
                unir(i,j);
            }
            else
            {
                if(estan_unidos(i,j))
                {
                    correctos++;
                }
                else
                {
                    incorrectos++;
                }
            }
        }
        printf("%d,%d\n", correctos, incorrectos);
    }
    return 0;
}
