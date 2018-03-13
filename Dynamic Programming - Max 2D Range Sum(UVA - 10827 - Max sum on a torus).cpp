#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mat[150][150], n, casos;
    scanf("%d",&casos);
    while(casos--)
    {
        scanf("%d",&n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                scanf("%d",&mat[i][j]);
                mat[i][j+n] = mat[i+n][j] = mat[i+n][j+n] = mat[i][j];
            }
        }

        for(int i = 0; i<2*n; i++)
        {
            for(int j = 0; j<2*n; j++)
            {
                if(i > 0)
                {
                    mat[i][j] += mat[i-1][j];
                }
                if(j > 0)
                {
                    mat[i][j] += mat[i][j-1];
                }
                if(i>0 && j>0)
                {
                    mat[i][j] -= mat[i-1][j-1];
                }
            }
        }

        /**
            Calcular la suma maxima
        **/
        int sumaP = 0, maxSuma = -100*75*75;
        for(int i = 0; i<2*n; i++)
        {
            for(int j = 0; j<2*n; j++)
            {

                for(int a = i; a<2*n; a++)
                {
                    if(a == i+n)
                    {
                        break;
                    }
                    for(int b = j; b < 2*n; b++)
                    {
                        if(b == j+n)
                        {
                            break;
                        }

                        sumaP = mat[a][b];

                        if(i > 0)
                        {
                            sumaP -= mat[i-1][b];
                        }
                        if(j > 0)
                        {
                            sumaP -= mat[a][j-1];
                        }
                        if(i>0 && j>0)
                        {
                            sumaP += mat[i-1][j-1];
                        }
                        maxSuma = max(maxSuma, sumaP);
                    }
                }

            }
        }

        printf("%d\n",maxSuma);
    }
    return 0;
}
