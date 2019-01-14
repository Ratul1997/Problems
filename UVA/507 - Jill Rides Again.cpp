#include <bits/stdc++.h>
using namespace std;
int  start_num , ed_num;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int test;
	int arr[20005];
	cin>>test;
	for(int t = 1;t<=test ;t++){
		int n;
		cin>>n;
		
		n--;
		for(int i = 1;i<=n;i++){
			
			cin>>arr[i];
			
		}

		int ans=0, sum=0;
		int tmp = 1; 
		for(int i = 1 ; i <= n; ++i)
		{
		    if(sum + arr[i] >= 0)sum+=arr[i];
		    else sum  = 0,tmp = i+1;


		    if(sum>ans  || (sum == ans && ((i- tmp)>(ed_num-start_num)))){
		    	start_num = tmp;
		    	ed_num = i;
		    }
		    ans = max(ans, sum);
		}

		if(ans<=0){
			printf("Route %d has no nice parts\n",t );
		}else{
			printf("The nicest part of route %d is between stops %d and %d\n",t, start_num, ed_num+1 );

		}
	}
}