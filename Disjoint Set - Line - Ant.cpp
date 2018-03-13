#include <bits/stdc++.h>

#define vi vector<int>

const double EPS = 1e-7;

using namespace std;


class Point{
    public:
    double x,y;
    const bool operator < (const Point &other) const
    {
        return x <= other.x && y < other.y;
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};
class LineSegment {
    public:
        double x1, y1, x2, y2;
        double a, b, c;
        LineSegment(double x1,double y1, double x2,double y2)
        {
            this->x1 = x1;
            this->x2 = x2;
            this->y1 = y1;
            this->y2 = y2;
            a = y2 - y1;
            b = x1 - x2;
            c = a * x1 + b * y1;
        }
        bool intersects(LineSegment &other)
        {
            double det = a*other.b - other.a*b;
            if(det == 0)
            {
                Point a(x1,y1), b(x2,y2), c(other.x1, other.y1), d(other.x2, other.y2);
                if( b < a)
                {
                    swap(a,b);
                }
                if(d < c)
                {
                    swap(c,d);
                }
                return (b.x - c.x >= 0 && b.y - c.y >= 0 && d.x - a.x >=0 && d.y - a.y >= 0);

            }
            else
            {
                double x = (other.b*c - b*other.c)/det;
                double y = (a*other.c - other.a*c)/det;
                return min(x1, x2) <= x && x <= max(x1,x2) && min(y1,y2) <= y && y <= max(y1,y2)
                && min(other.x1, other.x2) <= x && x <= max(other.x1,other.x2) && min(other.y1,other.y2) <= y && y <= max(other.y1,other.y2);
            }
        }
};

class UnionFind {
    private: vi p, rank;
    int numSets;
    public:

        UnionFind(int N) {
            numSets = N;
            rank.assign(N,0);
            p.assign(N,0);
            for(int i = 0; i < N; i++) p[i] = i;
        }
        int findSet(int i) {
            return (p[i] == i)? i: (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
        void unionSet(int i, int j)
        {
            if(!isSameSet(i,j))
            {
                numSets--;
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else
                {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
        int numDisjointSets()
        {
            return numSets;
        }
};


int main (){
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        UnionFind disjoint(n);
        vector<LineSegment> lines;
        for(int i = 0; i < n; i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            lines.push_back(LineSegment(x1,y1,x2,y2));
            for(int j = 0; j < i; j++)
            {
                if(lines[i].intersects(lines[j]))
                {
                    disjoint.unionSet(i, j);
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin>>u>>v;
            if(disjoint.isSameSet(u-1, v-1))
            {
                cout<<"YES";
            }
            else
            {
                cout<<"NO";
            }
            cout<<endl;
        }
    }

}
