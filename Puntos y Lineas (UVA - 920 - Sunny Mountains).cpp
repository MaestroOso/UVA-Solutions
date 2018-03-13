#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
double PI = 3.141592;

double hypot(double a, double b)
{
    return (sqrt(a*a + b*b));
}

struct point
{
    double x, y;
    point()
    {
        x = 0.0;
        y = 0.0;
    }
    point(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    bool operator < (point other) const
    {
        if(fabs(x-other.x) > EPS)
        {
            return x<other.x;
        }
        else
        {
            return y<other.y;
        }
    }
    bool operator == (point other) const
    {
        return (fabs(x-other.x)<EPS && fabs(y-other.y)<EPS);
    }

};

double distancia(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line
{
    /** La linea se representa de la forma ax+by+c = 0 **/
    double a, b, c;
};



/**
    Calcular el punto x conocida la nueva y
**/
double xNuevo(line &l, double yMax){
    return ((-l.b/l.a)*yMax - (l.c/l.a));
}


/** Funcion que crea una linea a partir de puntos
    Se asume normalmente que la equacion tiene a b=1 excepto para lineas verticales donde b = 0**/
void lineaDePuntos(point p1, point p2, line &l)
{
    if(fabs(p1.x - p2.x) < EPS)
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else
    {
        l.a = -(p1.y - p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}

int main()
{
    int casos, n;
    double x,y;
    cin >> casos;
    while(casos--)
    {
        cin >> n;
        vector<point> p;
        for(int i = 0; i<n; i++)
        {
            cin >> x >> y;
            p.push_back(point(x,y));
        }
        sort(p.rbegin(),p.rend());
        double yMax = 0, dMax = 0;

        for(int i = 0; i<p.size()-1; i+=2)
        {
            if(p[i+1].y > yMax)
            {
                line l;
                lineaDePuntos(p[i],p[i+1],l);
                point aux(xNuevo(l,yMax), yMax);
                dMax += distancia(p[i+1],aux);
                yMax = p[i+1].y;
            }
        }

        printf("%.2f\n",dMax);
    }
    return 0;
}
