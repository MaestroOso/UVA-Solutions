#include <bits/stdc++.h>
using namespace std;
unsigned long long int dos = 2;
unsigned long long int potencia(unsigned long long int n){
    unsigned long long int res = 2;
    for(int i = 0; i<n-1; i++){
        res= res*dos;
    }
    return res;
}

int main()
{
    int casos;
    cin >> casos;
    while(casos--){
        unsigned long long int n, a , b, dosN, minimo;
        cin >> n >> a >> b;
        dosN = potencia(n);
        minimo = min(a,b);
        //cout << dosN << " " << minimo << endl;
        int dias = 0;
        while(dosN>minimo){
            //cout << dosN << endl;
            dosN = dosN/dos;
            dias++;
        }
        while(minimo%dosN!=0){
            //cout << dosN << endl;
            dosN = dosN/dos;
            dias++;
        }
        cout << dias << endl;
    }
    return 0;
}

