#include <bits/stdc++.h>
using namespace std;
bool solucion(int a,int b,int c,int n1,int n2,int n3)
{
    if(n1+n2+n3!=a)
    {
        return false;
    }
    if((n1*n2*n3)!=b)
    {
        return false;
    }
    if(((n1*n1)+(n2*n2)+(n3*n3))!=c)
    {
        return false;
    }
    return true;
}

bool evaluar(int a,int b,int c)
{
    for(int i = -100; i<=100; i++)
    {
        for(int j = -100; j<=100; j++)
        {
            if(j==i)
            {
                continue;
            }
            for(int k = -100; k<=100; k++)
            {
                if(k==j || k==i)
                {
                    continue;
                }
                if(solucion(a,b,c,i,j,k))
                {
                    cout << i << " " << j << " " << k << endl;
                    return true;
                }
            }
        }
    }
    cout << "No solution.\n";
    return false;
}

int main()
{
    int casos, a, b, c, n1, n2, n3;
    cin >> casos;
    while(casos--)
    {
        cin >> a >> b >> c;
        evaluar(a,b,c);
    }
    return 0;
}
