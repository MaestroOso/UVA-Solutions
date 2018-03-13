#include <bits/stdc++.h>
using namespace std;
/** 1 va a ser suma
    2 va a ser resta
    3 va a ser multiplicacion
**/
int evaluar(int a, int b, int c, int d, int e, int op1, int op2, int op3, int op4)
{
    int resultado = 0;
    switch(op1)
    {
    case 1:
        resultado = a+b;
        break;
    case 2:
        resultado = a-b;
        break;
    case 3:
        resultado = a*b;
        break;
    }
    /** ------------------ **/
    switch(op2)
    {
    case 1:
        resultado = resultado+c;
        break;
    case 2:
        resultado = resultado-c;
        break;
    case 3:
        resultado = resultado*c;
        break;
    }
    /** ------------------ **/
    switch(op3)
    {
    case 1:
        resultado = resultado+d;
        break;
    case 2:
        resultado = resultado-d;
        break;
    case 3:
        resultado = resultado*d;
        break;
    }
    /** ------------------ **/
    switch(op4)
    {
    case 1:
        resultado = resultado+e;
        break;
    case 2:
        resultado = resultado-e;
        break;
    case 3:
        resultado = resultado*e;
        break;
    }
    //cout << resultado << " ";
    return resultado;
}

int main()
{
    vector<int> letras(5);
    while(cin>>letras[0]>>letras[1]>>letras[2]>>letras[3]>>letras[4])
    {
        if(letras[0]==0 && letras[1]==0 && letras[2]==0 && letras[3]==0 && letras[4]==0)
        {
            break;
        }
        sort(letras.begin(),letras.end());
        bool posible = false;
        do{
            for(int i = 1; i<=3; i++)
            {
                for(int j = 1; j<=3; j++)
                {
                    for(int k = 1; k<=3; k++)
                    {
                        for(int l = 1; l<=3; l++)
                        {
                            if(evaluar(letras[0],letras[1],letras[2],letras[3],letras[4],i,j,k,l)==23)
                            {
                                posible = true;
                            }
                        }
                    }
                }
            }
        }while(next_permutation(letras.begin(),letras.end()));

        if(posible)
        {
            cout<<"Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }

    }
    return 0;
}
