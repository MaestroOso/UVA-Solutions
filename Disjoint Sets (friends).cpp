#include <bits/stdc++.h>
using namespace std;

struct disjointSets
{
    vector<int> papas, tamagno;
    int num_conj;
    disjointSets(int numeroC)
    {
        for(int i =0; i<numeroC; i++)
        {
            papas.push_back(i);
            tamagno.push_back(1);
        }
        num_conj = numeroC;
    }

    bool same(int num1,int  num2)
    {
        if(papa(num1)==papa(num2))
        {
            return true;
        }
        return false;
    }

    void unionC(int num1, int num2)
    {
        int aux1 = papa(num1), aux2 = papa(num2);
        if(same(aux1,aux2))
        {
            return;
        }
        if(tamagno[aux1]>tamagno[aux2])
        {
            papas[aux2] = aux1;
            tamagno[aux1]+=tamagno[aux2];
            tamagno[aux2]=0;
            //num_conj--;
            return;
        }
        else
        {
            papas[aux1] = aux2;
            tamagno[aux2]+=tamagno[aux1];
            tamagno[aux1]=0;
            //num_conj--;
            return;
        }
    }

    int papa(int num1)
    {
        while(papas[num1]!=num1)
        {
            num1 = papas[num1];
        }
        return num1;
    }

};

int main()
{
    int casos;
    cin >> casos;
    while(casos--)
    {
        int num, relaciones;
        cin >> num >> relaciones;
        int p1, p2;
        disjointSets amigos(num);
        for(int i = 0; i<relaciones; i++){
            cin >> p1 >> p2;
            p1--;
            p2--;
            amigos.unionC(p1,p2);
        }
        sort(amigos.tamagno.begin(),amigos.tamagno.begin()+amigos.tamagno.size());
        cout << amigos.tamagno[amigos.tamagno.size()-1] << endl;
    }

    return 0;
}

