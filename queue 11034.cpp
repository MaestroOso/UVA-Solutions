#include<bits/stdc++.h>
using namespace std;
bool arreglo[1000000];
int main()
{
    int c=0,l=0,m=0,v=0,acum=0;
    string lado="";
    cin>>c;
    while(c--)
    {
        bool lleno=false;
        cin>>l>>m;
        l*=100;
        int cont=0;
        queue<int> der;
        queue<int> izq;
        bool vder=true, vizq=true;
        for(int i=0; i<m; i++)
        {
            cin>>v>>lado;
            if(lado=="left")
                izq.push(v);
            else
                der.push(v);
        }

        while(vizq || vder)
        {
            while(!lleno)
            {
                if(!izq.empty())
                {
                    if((acum+izq.front())<=l)
                    {
                        //cout<<"Cargo "<<izq.front()<<endl;
                        acum+=izq.front();
                        izq.pop();
                    }
                    else
                        lleno=true;
                }
                else
                {
                    vizq=false;
                    break;
                }
            }
            if(!der.empty() || !izq.empty() || acum!=0)
                cont++;
            else
                break;
            //cout<<"salio a der "<<cont<<endl;
            acum=0;
            lleno=false;
            while(!lleno)
            {
                if(!der.empty())
                {
                    if((acum+der.front())<=l)
                    {
                        //cout<<"Cargo "<<der.front()<<endl;
                        acum+=der.front();
                        der.pop();
                    }
                    else
                        lleno=true;
                }
                else
                {
                    vder=false;
                    break;
                }
            }
            if(!der.empty() || !izq.empty() || acum!=0)
                cont++;
            else
                break;
            //cout<<"Salio a izq "<<cont<<endl;
            acum=0;
            lleno=false;
        }
        cout<<cont<<endl;
    }
    return 0;
}
