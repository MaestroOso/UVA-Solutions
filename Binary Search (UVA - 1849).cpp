#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  per1=0, per2=0;
    while(cin>>per1>>per2 && per1 && per2)
    {
        int cont=0, aux;
        vector<int> queso(per1);
        for(int i=0;i<per1;i++)
            cin>>queso[i];
        for(int i=0;i<per2;i++)
            {
                cin>>aux;
                if(binary_search(queso.begin(),queso.begin()+queso.size(),aux))
                    cont++;
            }
        cout<<cont<<endl;
    }
    return 0;
}
