#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265359;

double hypot(double a, double b)
{
    return (sqrt(a*a + b*b));
}

int main()
{
    int numPlanetas, tiempo;
    double x, y;
    while(cin>>numPlanetas>>tiempo){
        /**
        Posicion 0 --> Px
        Posicion 1 --> Py
        Posicion 2 --> Radio
        Posicion 3 --> Periodo
        **/
        vector<vector<double> > datosPlanetas(numPlanetas, vector<double>(4,0));
        for(int i = 0; i<numPlanetas; i++){
            cin >> datosPlanetas[i][2] >> datosPlanetas[i][3];
        }
        for(int i = 0; i<numPlanetas; i++){
            if(i==0){
                x = datosPlanetas[i][2] * cos(((2*PI)/datosPlanetas[i][3])*tiempo);
                y = datosPlanetas[i][2] * sin(((2*PI)/datosPlanetas[i][3])*tiempo);
                datosPlanetas[i][0] = x;
                datosPlanetas[i][1] = y;
                printf("%.4f", hypot(datosPlanetas[i][0],datosPlanetas[i][1]));
            } else {
                x = datosPlanetas[i-1][0] + datosPlanetas[i][2] * cos(((2*PI)/datosPlanetas[i][3])*tiempo);
                y = datosPlanetas[i-1][1] + datosPlanetas[i][2] * sin(((2*PI)/datosPlanetas[i][3])*tiempo);
                datosPlanetas[i][0] = x;
                datosPlanetas[i][1] = y;
                printf("%.4f", hypot(datosPlanetas[i][0],datosPlanetas[i][1]));
            }
            if(i!=numPlanetas-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
