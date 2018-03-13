#include <bits/stdc++.h>
using namespace std;

int asignar(vector<int> &jugadores, int ultimo, int turnos){
    for(int i = 0; i<turnos; i++, ultimo++){
        if(ultimo==jugadores.size()){
            ultimo = 0;
        }
        jugadores[ultimo]++;
    }
    ultimo--;
    return ultimo;
}

int eliminar(vector<int> &jugadores, int ultimo){
    int nuevap;
    if(ultimo+1==jugadores.size()){
        nuevap = 0;
    } else {
        nuevap = ultimo;
    }
    jugadores.erase(jugadores.begin()+ultimo);
    return nuevap;
}

bool ganar(vector<int> &jugadores){
        for(int i = 0; i<jugadores.size(); i++){
            if(jugadores[0]!=jugadores[i]){
                return false;
            }
        }
        return true;
}


int main(){
    int num;
    while(cin>>num && num!=0){
        vector<int> jugadores(num, 0);
        int turnos;
        cin >> turnos;
        bool finp = false;
        int ultimo = 0;
        while (!finp){
            ultimo = asignar(jugadores, ultimo, turnos);
            ultimo = eliminar(jugadores, ultimo);
            finp = ganar(jugadores);
        }
        cout << jugadores.size() << " " << jugadores[0] << endl;
    }
    return 0;
}
