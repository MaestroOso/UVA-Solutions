#include <bits/stdc++.h>
using namespace std;
bool ordenado(int vec[],int tam)
{
    for(int i=1; i<tam; ++i)
        if(vec[i]<vec[i-1])
            return false;
    return true;
}
int mapas=0;
void solve(int vec[],int tam)
{
    if(ordenado(vec,tam))
    {
        mapas++;
        return;
    }
    for(int i=0;i<tam-1;i++)
        if(vec[i]>vec[i+1])
        {
            swap(vec[i],vec[i+1]);
            solve(vec,tam);
            swap(vec[i],vec[i+1]);
        }
}
int main()
{
    int casos=0, nums;
    while(cin>>nums && nums)
    {
        int vec[5],res;
        for(int i=0; i<nums; ++i)
            cin>>vec[i];
        if(!ordenado(vec,nums))
            solve(vec,nums);
        printf("There are %d swap maps for input data set %d.\n",mapas,++casos);
        mapas=0;
    }
    return 0;
}
