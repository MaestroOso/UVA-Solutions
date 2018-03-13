#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num[20010], n, casos, sum, ans, c = 1, pi, pj, a, b;
    cin >> casos;
    while(casos--)
    {
        /**
            Leer los datos
        **/
        cin >> n;
        for(int i = 1; i<n; i++)
        {
            cin >> num[i];
        }

        /**
            Calcular la maxima suma en 1D -- Programación Dinámica
        **/
        sum = ans = 0, pi = 1, a=1;
        for(int i = 1; i<n; i++)
        {
            sum+=num[i];

            if(sum < 0)
            {
                sum = 0;
                a = i+1;
            }

            if(sum > ans || (sum == ans && i - a > pj - pi))
            {
                pi = a;
                pj = i+1;
                ans = sum;
            }

        }
        if(ans>0)
        {
            printf("The nicest part of route %d is between stops %d and %d\n", c, pi, pj);
        }
        else
        {
            printf("Route %d has no nice parts\n", c);
        }
        c++;
    }
    return 0;
}
