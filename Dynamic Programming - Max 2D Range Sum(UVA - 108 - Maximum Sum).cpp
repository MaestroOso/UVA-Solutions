#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mat[100][100], n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> mat[i][j];

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
    int sumaP = 0, maxSuma = -1000000;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {

            for(int a = i; a<n; a++)
            {
                for(int b = j; b<n; b++)
                {
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

    cout << maxSuma << endl;

    return 0;
}
