#include <bits/stdc++.h>
using namespace std;
int kadans(vector<int> &arr,int n)
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
int main(){
	//freopen("input.txt","r",stdin);
	int n;
	while(cin>>n && n!=0){
		vector<int>v;
		for(int i = 0 ;i<n;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		int num = kadans(v,n);
		if(num<=0){
			cout<<"Losing streak."<<endl;
		}
		else{
			printf("The maximum winning streak is %d.\n",num );
		}
	}
}