#include<bits/stdc++.h>
using namespace std;

int x[]={0,1,-1,0,0};
int y[]={0,0,0,1,-1};
int main()
{
    int r=0,c=0,n=0, caso=1;
    scanf("%d %d %d",&r,&c,&n);
    while(r || c || n)
    {
        vector<pair<int,int> > prob(n);
        int posx=0,posy=0;
        bool escape=true;
        for(int i=0;i<n;i++)
            scanf("%d %d",&(prob[i].first),&(prob[i].second));
        scanf("%d %d",&posx,&posy);
        for(int m=0;m<5;m++)
        {
            if((posx+x[m]<r && posy+y[m]<c)&&(posx+x[m]>=0 && posy+y[m]>=0))
            {
                for(int i=0;i<prob.size();i++)
                {
                    if(prob[i].first==posx+x[m] || prob[i].second==posy+y[m])
                    {
                        escape=false;
                        break;
                    }
                    escape=true;
                }
                if(escape)
                    break;
            }
        }
        if(escape)
            printf("Case %d: Escaped again! More 2D grid problems!\n",caso++);
        else
            printf("Case %d: Party time! Let's find a restaurant!\n",caso++);

    scanf("%d %d %d",&r,&c,&n);
    }
    return 0;
}
