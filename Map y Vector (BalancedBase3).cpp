#include <bits/stdc++.h>
using namespace std;
int potencias[] = {729,243,81,27,9,3,1};
void imprimir(map<int,vector<int> >&mapa, int num){
    vector<int> res = mapa[num];
    bool bandera = false;
    for(int i = 0; i<7; i++){
        if(res[i]!=0){
            bandera=true;
            if(res[i]==1){
                cout<<"+";
            } else {
                cout << "-";
            }
        } else if(bandera){
            cout << "0";
        }
    }
}

int main()
{
    int res;
    vector<int> comb(7,0);
    map<int,vector<int> >mapa;
    for(int a = -1; a<2; a++)
    {
        for(int b = -1; b<2; b++)
        {
            for(int c = -1; c<2; c++)
            {
                for(int d = -1; d<2; d++)
                {
                    for(int e = -1; e<2; e++)
                    {
                        for(int f = -1; f<2; f++)
                        {
                            for(int g = -1; g<2; g++)
                            {
                                res = (potencias[0]*a)+(potencias[1]*b)+(potencias[2]*c)+(potencias[3]*d);
                                res+=(potencias[4]*e)+(potencias[5]*f)+(potencias[6]*g);
                                comb[0] = a;
                                comb[1] = b;
                                comb[2] = c;
                                comb[3] = d;
                                comb[4] = e;
                                comb[5] = f;
                                comb[6] = g;
                                mapa[res] = comb;
                            }
                        }
                    }
                }
            }
        }
    }
    int n;
    cin>>n;
        imprimir(mapa,n);
        cout << "\n";
    return 0;
}
