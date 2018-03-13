#include<bits/stdc++.h>

using namespace std;

char g[100][100];
char c;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs(int x,int  y){
    queue<pair <int, int> > q;
    q.push(make_pair(x, y));
    int cont = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        //cout<<curr.first<<" "<<curr.second<<endl;
        if (curr.second >= m)
            curr.second = 0;
        if (curr.second < 0)
            curr.second = m-1;
        if (curr.first < 0 || curr.first >= n) continue;
        if (g[curr.first][curr.second] != c) continue;
        g[curr.first][curr.second] = '*';
        cont++;
        for(int i = 0; i < 4; i++)
        {
                q.push(make_pair(curr.first+dx[i], curr.second+dy[i]));
        }
    }
    return cont;
}
int main(){
    while(cin>>n>>m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>g[i][j];
            }
        }
        int x, y, mayor = 0;
        cin>>x>>y;
        c =g[x][y];
        bfs(x,y);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    if(g[i][j] == c)
                    {
                        mayor = max( bfs(i, j), mayor);
                    }
            }
        }
        cout<<mayor<<endl;
    }
    return 0;
}
