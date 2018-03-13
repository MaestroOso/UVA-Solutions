#include <bits/stdc++.h>
using namespace std;
struct Heroe{
    int acur, speed, stup;
    string nombre;

    bool operator < (Heroe other) const {
        if(acur > other.acur){
            return 1;
        }
        if(acur < other.acur){
            return 0;
        }

        if(speed > other.speed){
            return 1;
        }
        if(speed < other.speed){
            return 0;
        }

        if(stup < other.stup){
            return 1;
        }
        if(stup > other.stup){
            return 0;
        }

        return nombre<other.nombre;
    }

};

int main(){
    int casos;
    cin >> casos;
    Heroe h;
    vector<Heroe> heroes(casos);
    int j = 0;
    while(casos--){
        cin >> h.nombre >> h.acur >> h.speed >> h.stup;
        heroes[j] = h;
        j++;
    }
    sort(heroes.begin(),heroes.end());
    for(int i = 0; i<heroes.size(); i++){
        cout << heroes[i].nombre << endl;
    }
    return 0;
}
