#include <bits/stdc++.h>
using namespace std;
int main(){
    double num, casos, aux, cont;
    cin >> casos;
    while(casos--){
        cont = 0;
        cin >> num;
        double promedio=0;
        vector<double> notas(num,0);
        for(int i = 0; i<num; i++){
            cin >> notas[i];
            promedio+=notas[i];
        }
        promedio=promedio/num;
        for(int i = 0; i<num; i++){
            if(notas[i]>promedio){
                cont++;
            }
        }
        printf("%.3f",(cont*100)/num);
        cout << "%" << endl;
    }


return 0;
}
