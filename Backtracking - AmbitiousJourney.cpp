#include <bits/stdc++.h>
using namespace std;

int movx[] = {1,0};
int movy[] = {0,1};

int imprimirVector(vector<vector<int> >&sumaParcial)
{
    for(int i = 0; i<sumaParcial.size(); i++)
    {
        for(int j = 0; j<sumaParcial.size(); j++)
        {
            cout << sumaParcial[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int backtracking(int posx, int posy, int suma, vector<vector<int> >&matriz, vector<vector<int> >&sumaParcial)
{
    int n = matriz.size(), nx, ny, maximo[2] = {0,0};
    //imprimirVector(sumaParcial);
    if(posx < 0 || posy < 0 || posx >= n || posy >= n)
    {
        return -1;
    }
    if(posx == n-1 && posy == n-1)
    {
        sumaParcial[posx][posy] = matriz[posx][posy];
        return sumaParcial[posx][posy];
    }
    //imprimirVector(sumaParcial);
    for(int i = 0; i<2; i++)
    {
        nx = posx+movx[i];
        ny = posy+movy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n)
        {
            if(sumaParcial[nx][ny] == -1)
            {
                maximo[i] = backtracking(nx,ny, suma+matriz[posx][posy],matriz,sumaParcial);
            }
            else
            {
                maximo[i] = sumaParcial[nx][ny];
            }
        }
    }
    sumaParcial[posx][posy] = matriz[posx][posy] + max(maximo[0],maximo[1]);
    return sumaParcial[posx][posy];
}


int main()
{
    int n = 0;
    while(scanf("%d",&n) && n)
    {
        vector<vector<int> >matriz(n,vector<int>(n,0));
        vector<vector<int> >sumaParcial(n,vector<int>(n,-1));
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }
        backtracking(0,0,0,matriz,sumaParcial);
        //imprimirVector(sumaParcial);
        printf("%d\n",sumaParcial[0][0]);
    }
    return 0;
}
