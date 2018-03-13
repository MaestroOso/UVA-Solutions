#include <bits/stdc++.h>
using namespace std;

int dom[32];
int inicial[16][2];
bool usados[16];
bool posible;
int n, m;

void recursion(int p){
    if(p == n){
        if(dom[2*p] == dom[(2*p)-1]){
            posible = true;
        }
        return;
    }

    for(int i = 0; i<m; i++){
        if(usados[i]){
            continue;
        }
        /** Usar inicial **/
        int a = inicial[i][0], b = inicial[i][1];
        if(a == dom[(2*p)-1]){
            dom[2*p] = a;
            dom[(2*p)+1] = b;
            usados[i] = true;
            recursion(p+1);
            usados[i] = false;
        }
        /** Usar reversed **/
        if(b == dom[(2*p)-1]){
            usados[i] = true;
            dom[2*p] = b;
            dom[(2*p)+1] = a;
            recursion(p+1);
            usados[i] = false;
        }
    }

}

int main(){
    while(cin >> n && n){
        posible = false;
        memset(dom, 0, sizeof dom);
        memset(usados, false, sizeof usados);

        n++;
        cin >> m;
        /** Fichas Iniciales **/
        cin >> dom[0] >> dom[1];
        cin >> dom[n*2] >> dom[(n*2)+1];

        for(int i = 0; i<m; i++){
            cin >> inicial[i][0] >> inicial[i][1];
        }
        recursion(1);
        if(posible){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
