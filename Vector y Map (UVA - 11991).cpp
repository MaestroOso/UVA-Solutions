#include <bits/stdc++.h>
using namespace std;

int queso(map<int, vector<int> > &numeros, int n, int oc){
    oc--;
    if(numeros.find(n)==numeros.end())
        return 0;

    if(numeros[n].size()-1<oc)
        return 0;

    return numeros[n][oc]+1;
}


int main()
{
    int tam, bus, aux;
    while(cin>>tam>>bus){
        map<int,vector<int> > numeros;
        for(int i = 0; i<tam; i++){
            cin >> aux;
            numeros[aux].push_back(i);
        }
        int oc, num;
        for(int i = 0; i<bus; i++){
            cin >> oc >> num;
            printf("%d\n",queso(numeros,num,oc));
        }
    }
    return 0;
}
