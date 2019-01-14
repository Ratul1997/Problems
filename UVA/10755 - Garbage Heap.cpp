#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void kadans(vector<ll> &arr,int n)
{
    ll ans=arr[0],sum=0;
    for(int i=1; i<n; i++) ///if all values are negative
    {
        ans=max(ans,arr[i]);
    }
    if(ans < 0){
    	cout<<ans<<endl;
    	return;

    }

    ans=0;
    for(int i = 0 ; i < n; ++i)
    {
        if(sum + arr[i] > 0)sum+=arr[i];
        else sum  = 0;

        cout<<sum<<endl;
        ans = max(ans,sum);

    }
    cout<<ans<<endl;
    
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	cin>>test;
	while(test--){
		int a,b,c;
		cin>>a>>b>>c;
		vector<ll>v;
		for(int i = 1 ;i<= a*b*c ;i++){
			ll aa;
			cin>>aa;
			v.push_back(aa);
		}

		kadans(v,a*b*c);
		if(test)puts("");
	}
}