#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

double respuesta(double p, double q, double r, double s, double t, double u, double x)
{
    double res = 0;
    res = p*1/exp(x);
    res+= q*sin(x);
    res+= r*cos(x);
    res+= s*tan(x);
    res+= t*(x*x);
    res+= u;
    return res;
}


int main()
{
    double p,q,r,s,t,u;
    double ans, ans2;
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        ans = respuesta(p,q,r,s,t,u,0.0);
        ans2 = respuesta(p,q,r,s,t,u,1.0);
        if(ans<0.0 && ans2<0.0)
        {
            cout << "No solution\n";
            continue;
        }
        if(ans>0.0 && ans2>0.0)
        {
            cout << "No solution\n";
            continue;
        }

        /** Binary Search **/
        double hi = 1.0, lo = 0.0, mid = 0.0, ans=0.0;
        while(fabs(hi-lo)>=EPS){
            mid = (lo+hi)/2.0;
            if(respuesta(p,q,r,s,t,u,mid)<0.0){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("%.4f\n",mid);
    }

    return 0;
}
