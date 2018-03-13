#include <map>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int veces;
    while(cin>>veces && veces!= 0)
    {

        map<vector<int>,int> mapa;
        vector<int> queso;
        int a;
        int n = 0;
        map<vector<int>,int>::iterator it;
        int mayor = 0;
        int popular=0;

        while(veces--)
        {

            for(int i = 0; i<5; i++)
            {
                cin >> a;
                queso.push_back(a);
            }
            sort(queso.begin(),queso.end());
            mapa[queso]++;
            queso.clear();
        }

        for(it=mapa.begin(); it!=mapa.end(); it++)
        {
            n = it->second;
            if(mayor <= n)
            {
                mayor = n;
            }
        }
        for(it=mapa.begin(); it!=mapa.end(); it++)
        {
            n = it->second;
            if(mayor == n)
            {
                popular = popular+n;
            }
        }
        cout << popular << endl;
    }
    return 0;
}
