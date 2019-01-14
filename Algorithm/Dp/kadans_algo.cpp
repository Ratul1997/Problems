#include<bits/stdc++.h>
using namespace std;
int kadans(int arr[],int n)
{
    int ans=arr[0],sum=0;
    for(int i=1; i<n; i++) ///if all values are negative
    {
        ans=max(ans,arr[i]);
    }
    if(ans < 0)return ans;

    ans=0;
    for(int i = 0 ; i < n; ++i)
    {
        if(sum + arr[i] > 0)sum+=arr[i];
        else sum  = 0;

        ans = max(ans,sum);
    }
    return ans;
}