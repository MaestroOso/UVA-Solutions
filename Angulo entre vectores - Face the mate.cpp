#include <bits/stdc++.h>
using namespace std;
float EPS = 1e-5;
float PI = 3.14159265;

float hypot(float a, float b)
{
    return (sqrt(a*a + b*b));
}

struct point
{
    float x, y;
    point()
    {
        x = 0.0;
        y = 0.0;
    }
    point(float x1, float y1)
    {
        x = x1;
        y = y1;
    }

};


float anguloEntreVectores(point u, point v){
    float prodPunto = u.x*v.x + u.y*v.y;
    float magnitud = hypot(u.x,u.y)*hypot(v.x,v.y);
    float angulo = acos(prodPunto/magnitud);
    return min(angulo, (float)360.0 - angulo);
}


int main()
{
    int casos;
    float x1,y1,u1,v1,x2,y2,u2,v2;
    cin >> casos;
    while(casos--)
    {
        scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&u1,&v1,&x2,&y2,&u2,&v2);
        point Rey(x1,y1), Reina(x2,y2), aux1(u1,v1), aux2(u2,v2);

        point rAux(Reina.x-Rey.x,Reina.y-Rey.y), rAux2(aux1.x-Rey.x,aux1.y-Rey.y);
        float heroe = anguloEntreVectores(rAux,rAux2);
        point qAux(Rey.x-Reina.x,Rey.y-Reina.y), qAux2(aux2.x-Reina.x,aux2.y-Reina.y);
        float heroine = anguloEntreVectores(qAux,qAux2);
        if( fabs(heroe-heroine) < EPS){
            printf("0\n");
        } else if(heroe<heroine)
        {
            printf("Hero\n");
        }
        else
        {
            printf("Heroine\n");
        }
    }
    return 0;
}
