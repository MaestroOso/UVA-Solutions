#include <bits/stdc++.h>
using namespace std;
int arr[20], solucion[20];

//void backtracking(int duracion, int suma);

int main()
{
    int duracion, numCD, xFinal = 0;
    while(cin>>duracion)
    {
        xFinal = 0;
        cin >> numCD;
        memset(arr,0,sizeof arr);
        for(int i = 0; i<numCD; i++)
        {
            cin >> arr[i];
        }
        int maximoAct = -100000, sumaParcial = 0;
        for(int x = 0; x < (1<<numCD); x++)
        {
            sumaParcial = 0;
            for(int j = 0; j<numCD; j++)
            {
                if( ((1<<j) & x) != 0)
                {
                    sumaParcial += arr[j];
                }
            }
            if(sumaParcial>=maximoAct && sumaParcial<=duracion)
            {
                maximoAct = sumaParcial;
                xFinal = x;
            }
        }
        for(int i = 0; i<20; i++){
            if( ((1<<i) & xFinal) != 0)
                {
                    cout << arr[i] << " ";
                }
        }
        cout << "sum:" << maximoAct << endl;
    }
    return 0;
}
