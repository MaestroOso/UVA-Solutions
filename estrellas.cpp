#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1,1,-1,1,-1};
int dy[] = {1, -1, 0, 0,1,-1,-1,1};

bool estrellas(vector<vector<char> > &cielo, int x, int y){
    bool bandera = true;

    for(int i=0; i<8; i++){
    if(x+dx[i]>=cielo.size()) continue;
    if(x+dx[i]<0) continue;
    if(y+dy[i]>=cielo[0].size()) continue;
    if(y+dy[i]<0) continue;
    if(cielo[x+dx[i]][y+dy[i]]!='.'){
        bandera = false;
    }
    }
    return bandera;
}

int main()
{
    int row, column, num=0;
    while(cin>>row>>column && row && column)
    {
        num=0;
        vector<vector<char> > cielo(row, vector<char> (column,'.'));
        for(int i = 0; i<row; i++)
        {
            for(int j= 0; j<column; j++)
            {
                cin>>cielo[i][j];
            }
        }
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(cielo[i][j] == '*')
            if(estrellas(cielo,i,j)){
                num++;
            }
        }
    }
    cout << num << endl;

    }

    return 0;
}
