#include <bits/stdc++.h>
using namespace std;

int numeroMayorQue(int num, vector<bool> si){
    for(int i = num; i<si.size(); i++){
        if(si[i] == false){
            return i;
        }
    }
    return -1;
}


int respuesta(vector<int> princesa, vector<int> principe){
    vector<bool> si(53,false);
    si[princesa[0]] = true;
    si[princesa[1]] = true;
    si[princesa[2]] = true;
    si[principe[0]] = true;
    si[principe[1]] = true;

    sort(princesa.rbegin(), princesa.rend());
    sort(principe.rbegin(), principe.rend());

    int a,b,c,d,e;
    a = princesa[0];
    b = princesa[1];
    c = princesa[2];
    d = principe[0];
    e = principe[1];

    //printf("%d %d %d %d %d\n",a,b,c,d,e);

    if(c>d){
        return -1;
    }

    if(b>d && c>e){
        return -1;
    }

    if(b>d && e>c){
        return -1;
    }

    if(a>d && c>e){
        return -1;
    }

    if(a>d && b>e){
        return -1;
    }

    if(a>d && e>b){
        return numeroMayorQue(b,si);//numero mas cercano mayor que b
    }

    if(d>a && c>e){
        return numeroMayorQue(a,si);//numero mas cercano mayor que a
    }

    if(d>a && b>e){
        return numeroMayorQue(a,si);//numero mas cercano mayor que a
    }

    if(d>a && a>e){
        return numeroMayorQue(b,si);//numero mas cercano mayor a b
    }

    if(d>a && e>a){
        return numeroMayorQue(1,si);//menor numero posible encontrado
    }

    return 123456789;
}


int main(){
    vector<int> princesa(3,0), principe(2,0);
    while(true){
        cin >> princesa[0] >> princesa[1] >> princesa[2] >> principe[0] >> principe[1];
        if(princesa[0]==0 && princesa[1]==0 && princesa[2]==0 && principe[0] == 0 && principe[1] == 0){
            break;
        }
        cout << respuesta(princesa,principe) << endl;
    }
    return 0;
}
