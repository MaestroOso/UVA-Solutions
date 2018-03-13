#include <bits/stdc++.h>
using namespace std;
double const EPS = 1e-6;

bool respuesta(vector<double> &pie, int numeroAmigos, double tamPersona)
{
    int cont = 0;
    for(int i = 0; i<pie.size(); i++)
    {
        cont+= pie[i]/tamPersona;
    }
    if(cont >= numeroAmigos)
    {
        return true;
    }
    return false;
}

int main()
{
    int casos, numeroPies, numeroAmigos;
    scanf("%d",&casos);
    while(casos--)
    {
        //cin >> numeroPies >> numeroAmigos;
        scanf("%d%d",&numeroPies,&numeroAmigos);
        numeroAmigos++;
        vector<int> radio(numeroPies);
        vector<double> pies(numeroPies);
        for(int i = 0; i<numeroPies; i++)
        {
            scanf("%d",&radio[i]);
        }
        for(int i = 0; i<numeroPies; i++){
            pies[i] = radio[i]*radio[i]*M_PI;
        }
        sort(pies.begin(),pies.end());

        /** Binary Search **/
        double hi = pies[pies.size()-1], lo = 0.0, mid = 0.0;
        while(fabs(hi-lo)>=EPS)
        {
            mid = (hi+lo)/2;
            if(respuesta(pies,numeroAmigos,mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        printf("%.4f\n",mid);
    }
    return 0;
}
