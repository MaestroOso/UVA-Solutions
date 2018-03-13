#include <bits/stdc++.h>
using namespace std;
int main()
{
    string basura;
    int tiempo, elemento, impresiones;
    map<int,int> queso;
    while(cin>>basura && basura!="#")
    {
        cin >> elemento;
        cin  >>tiempo;
        queso[elemento] = tiempo;
    }
    cin >> impresiones;

    map<int,int>::iterator it;

    for(int i = 1; impresiones>0 ; i++)
    {
        for(it=queso.begin(); it!=queso.end(); it++){
            if(i%it->second==0){
                cout<< it->first << endl;
                impresiones--;
            }
        }
    }

    return 0;
}
