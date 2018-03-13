#include <bits/stdc++.h>
using namespace std;
long long int m=1000007;
vector<long long int> sumasparciales(1001);
vector<long long int> potencias(1001,-1);

long long int potencia(int pos)
{
    if(potencias[pos]!=-1)
        return potencias[pos];
    if(pos==0)
    {
        return potencias[pos]=1;
    }
    if(pos==1)
        return potencias[pos]=2;
    long long int prov=((potencia(pos/2)%m)*(potencia(pos/2)%m))%m;
    if(pos&1)
        prov=(prov*2)%m;
    return potencias[pos]=prov;

}

void calcularsumas()
{
    sumasparciales[0]=1;
    for(int i=1; i<1001; i++)
    {
        sumasparciales[i]= (sumasparciales[i-1] + potencia(i))%m;
    }
}

int main()
{
    int desde, hasta;
    calcularsumas();
    long long int res;
    while(true)
    {

        scanf("%d %d",&desde,&hasta);
        if(desde==-1 && hasta==-1)
            break;
        if(desde==0)
            res=sumasparciales[hasta];
        else
            res=((sumasparciales[hasta]-sumasparciales[desde-1])+m)%m;
        cout<<res<<endl;
    }

    return 0;
}
