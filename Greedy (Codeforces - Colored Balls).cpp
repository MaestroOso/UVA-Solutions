#include <bits/stdc++.h>
using namespace std;
int arr[502];
int n;

int minimo(int mini)
{
    if(mini == 0){
        return INT_MAX;
    }
    int ans = 0;
    for(int i = 0; i<n; ++i)
    {
        if(arr[i]%mini == 0)
        {
            ans+=arr[i]/mini;
        }
        else if(arr[i]%mini == 1)
        {
            ans+=(arr[i]/mini);
        }
        else if(arr[i]%mini == mini-1)
        {
            ans+=(arr[i]/mini) + 1;
        }
        else
        {
            return INT_MAX;
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    int mini = INT_MAX, ans = mini;
    for(int i = 0; i<n; ++i)
    {
        cin >> arr[i];
        mini = min(arr[i],mini);
    }
//    for(int i = 1; i<=mini; i*=2)
//    {
        ans = min(ans,minimo(mini));
        ans = min(ans,minimo(mini/2));
        ans = min(ans,minimo(mini/2 + 1));
//    }
    cout << ans << endl;
    return 0;
}
