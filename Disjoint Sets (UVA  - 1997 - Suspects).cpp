#include<bits/stdc++.h>

using namespace std;

struct ds
{
    vector<int> p, tam;
    int nc;
    ds (int num)
    {   nc=num;
        for(int i=0; i<nc; i++)
        {
            p.push_back(i);
            tam.push_back(1);
        }
    }

    int papa(int x)
    {
        if(p[x]==x) return x;
        return(p[x]=papa(p[x]));
    }

    bool same(int uno, int dos)
    {
        int papa1 = papa(uno), papa2 = papa(dos);
        if(p[papa1]==p[papa2])
            return true;
        return false;
    }
    void unir(int primero,int segundo)
    {
        int p1 = papa(primero), p2=papa(segundo);
        if(same(p1,p2)){
            return;
        }
        if(tam[p1]>=tam[p2])
        {
        tam[p1]+=tam[p2];
        tam[p2]=0;
        p[p2]=p1;
        return;
        }
        else{
        tam[p2]+=tam[p1];
        tam[p1]=0;
        p[p1]=p2;
        return;
        }
    nc--;
    }
    int mayortam()
    {
        int mayor=tam[0];
        for(int i=1;i<tam.size();i++)
            if(mayor<tam[i])
                mayor=tam[i];
    return mayor;
    }
    int menortam()
    {
        int menor=tam[0];
        for(int i=1;i<tam.size();i++)
            if(menor>tam[i])
                menor=tam[i];
    return menor;
    }

};

int main(){
    int numero_est, num_grupos, persona1, persona2;
    while(cin>>numero_est>>num_grupos && (numero_est || num_grupos))
    {
        ds hola(numero_est);
        int aux;
        for(int i = 0; i<num_grupos; i++)
        {
            cin >> aux;
            if(aux==0){}
            else if(aux==1)
            {
                cin >> persona1;
                hola.unir(persona1,persona1);
            }
            else
            {
                cin >> persona1;
                for(int j = 1; j<aux; j++)
                {
                    cin >> persona2;
                    hola.unir(persona1,persona2);
                }
            }
        }
        cout << hola.tam[hola.p[0]] << endl;

    }
    return 0;
}
