#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos, c = 1, fil, col;
    long long pMax, mat[100][100];
    cin >> casos;
    while(casos--)
    {
        cin >> fil >> col >> pMax;
        for(int i = 0; i<fil; i++)
        {
            for(int j = 0; j<col; j++)
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
        long long sumaP = 0, maxSuma = 1000*75*75;
        int areaMax = 0;

        for(int i = 0; i<fil; i++)
        {
            for(int j = 0; j<col; j++)
            {
                for(int a = i; a<fil; a++)
                {
                    for(int b = j; b<col; b++)
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

                        if((a-i+1)*(b-j+1) >= areaMax && sumaP <= pMax)
                        {
                            if((a-i+1)*(b-j+1) > areaMax)
                            {
                                areaMax = (a-i+1)*(b-j+1);
                                maxSuma = sumaP;
                            }
                            else
                            {
                                maxSuma = min(maxSuma,sumaP);
                            }
                        }
                    }
                }
            }
        }
        if(areaMax > 0)
            printf("Case #%d: %d %d\n", c, areaMax, maxSuma);
        else
            printf("Case #%d: %d %d\n", c, 0, 0);
        c++;
    }
    return 0;
}
