#include <bits/stdc++.h>
using namespace std;
int main(){
    int Qnum, periodo, k;
    string instruccion;

    map<int, int> procesos;
    priority_queue<pair<int, int> >total;
    while(cin>>instruccion && instruccion=="Register"){
        cin >> Qnum >> periodo;
        periodo = (-1)*periodo;
        Qnum = (-1)*Qnum;
        procesos[Qnum] = periodo;
    }

    for(map<int, int>::iterator it = procesos.begin(); it!=procesos.end(); it++){
        for(int i = 1; i<=10000; i++){
            total.push(make_pair((it->second)*i,it->first));
        }
    }

    cin >> k;
    for(int i = 0; i<k; i++){
        cout << (-1) * total.top().second << endl;
        total.pop();
    }
    return 0;
}
