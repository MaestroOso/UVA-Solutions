#include <bits/stdc++.h>
using namespace std;
int main()
{
    int z,i,m,l;
    int h=1;
    while(cin>>z>>i>>m>>l)
    {
        if(z==0 && i==0 && m==0 && l==0)
        {
            return 0;
        }
        int cont=0;
        map<long,long> mapa;
        int aux = (z * l + i ) % m;
         mapa[aux]=0;
         bool bandera = true;
        while(bandera){
        aux= (z * aux + i ) % m;
        mapa[aux]++;
        if(mapa[aux] ==1 ){
        cont ++;
        }
        else{
        bandera=false;
        }



    }
cout<<"Case "<<h<<": "<<cont<<endl;
h++;
    }
      return 0;
}
