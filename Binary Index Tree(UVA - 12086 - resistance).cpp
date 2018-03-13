#include <bits/stdc++.h>
using namespace std;

void actualizar(int i, int valor, vector<int> &arbol)
{
    int tam = arbol.size();
    while(i<tam)
    {
        arbol[i]+=valor;
        i += (i&-i);
    }
}

int leer(int i, vector<int> &arbol)
{
    int suma = 0;
    while(i>0)
    {
        suma+=arbol[i];
        i -= (i&-i);
    }
    return suma;
}

int main()
{
    int casos, numPot, vez = 1;
    while(scanf("%d", &numPot) && numPot!=0)
    {
        vector<int> resistencia(numPot+1,0);
        vector<int> arbol(numPot+1,0);

        for(int i = 1; i<resistencia.size(); i++)
        {
            scanf("%d", &resistencia[i]);
            //cin >> resistencia[i];
        }

        for(int i = 1; i<arbol.size(); i++){
            actualizar(i,resistencia[i],arbol);
        }

        string linea;
        int num1, num2;
        if(vez!=1){
            cout << "\n";
        }
        printf("Case %d:\n", vez);
        while(cin>>linea && linea!="END")
        {
            cin >> num1 >> num2;
            if(linea=="M")
            {
                    printf("%d\n", leer(num2,arbol) - leer(num1-1,arbol));
            }
            else
            {
                int dif = num2 - resistencia[num1];
                resistencia[num1] = num2;
                actualizar(num1,dif,arbol);
            }
        }
        vez++;
    }
    return 0;
}
