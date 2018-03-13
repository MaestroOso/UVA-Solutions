#include <bits/stdc++.h>
using namespace std;
int main()
{
    string palabra="", adiv="";
   int ronda=0;
    while(cin>>ronda && ronda!=-1)
    {
        cout<<"Round "<<ronda<<endl;
        cin>>palabra>>adiv;
         int errores=0;
        int encontradas=0;
        for(int i=0; i<adiv.size(); i++)
        {
            bool bandera=0;
            for(int j=0; j<palabra.size(); j++)
            {
                if(adiv[i]==palabra[j])
                {
                    encontradas++;
                    palabra[j]='0';
                    bandera=3;
                }

                if(encontradas==palabra.size())
                    break;
            }
            if(!bandera)
            {
                errores++;
                if(errores==7)
                    break;
            }
            if(encontradas==palabra.size())
                break;
        }
        if(encontradas==palabra.size())
            cout<<"You win.\n";
        else
        if(errores<7)
           cout<<"You chickened out.\n";
        else
            cout<<"You lose.\n";
    }

    return 0;
}
