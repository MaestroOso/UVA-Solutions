#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
typedef pair<int,int> ii;

int x[] = {1,0,-1,0};
int y[] = {0,-1,0,1};

bool posValida(int r, int c, int x, int y){
    if(x<0 || x>=r){
        return false;
    }
    if(y<0 || y>=c){
        return false;
    }
    return true;
}


int bfs(vector<vector<int> > &mat, ii o, ii d){
    queue<pair<int,ii> > q;
    int num = 1;
    q.push(make_pair(num, o));
    while(!q.empty()){
        ii frente = q.front().second;
        num = q.front().first;
        q.pop();
        int a = frente.first, b = frente.second;
        for(int i = 0; i<4; i++){
            if(posValida(mat.size(),mat[0].size(),a+x[i],b+y[i])){
                if(mat[a+x[i]][b+y[i]] != INF){
                    if(mat[a+x[i]][b+y[i]] == 0){
                        mat[a+x[i]][b+y[i]] = num;
                        q.push(make_pair(num+1,ii(a+x[i],b+y[i])));
                    } else if(mat[a+x[i]][b+y[i]] > num+1){
                        mat[a+x[i]][b+y[i]] = num+1;
                    }
                }
            }
        }
    }
    return mat[d.first][d.second];
}

int main(){
    int r, c, nrb, rb, cb, aux, ox, oy, dx, dy;
    ii o, d;
    while(cin >> r >> c && (r||c)){
        vector<vector<int> > mat(r, vector<int>(c,0));
        cin >> nrb;
        for(int i = 0; i<nrb; i++){
            cin >> rb >> cb;
            for(int j = 0; j<cb; j++){
                cin >> aux;
                mat[rb][aux] = INF;
            }
        }
        cin >> ox >> oy >> dx >> dy;
        o = make_pair(ox,oy);
        d = make_pair(dx,dy);
        cout << bfs(mat,o,d) << endl;
    }
    return 0;
}
