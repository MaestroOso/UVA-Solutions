#include <bits/stdc++.h>
using namespace std;
int torre(int a, int b){
    return min(a,b);
}
int caballo(int a, int b){
    double x = a;
    double y = b;
    return floor((x*y+1)/2);
}
int rey(int a, int b){
    double x = a;
    double y = b;
    return floor((x+1)/2)*floor((y+1)/2);
}
int dama(int a, int b){
    return min(a,b);
}

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        char letra;
        int filas, columnas;
        cin >> letra >> filas >> columnas;
        switch(letra){
        case 'r':
            cout << torre(filas,columnas);
            break;
        case 'k':
            cout << caballo(filas,columnas);
            break;
        case 'Q':
            cout << dama(filas,columnas);
            break;
        case 'K':
            cout << rey(filas,columnas);
            break;
        }
        cout << endl;
    }
return 0;
}
