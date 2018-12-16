#include <bits/stdc++.h>
#define READ freopen("input.txt","r",stdin)
using namespace std;
int value[1005], weight[1005];
int dp[1005][35];

int n,Cap;
//bottomup approach
int knapsack(int w, int n){


	for(int i=0; i<=n; i++){
		for(int j=0; j<=w; j++){
			if(i==0 or j==0)continue;

			if( j- weight[i-1]>=0) dp[i][j]=max(dp[i-1][j], dp[i-1][j- weight[i-1]] + value[i-1]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

//topdown approach
int knapsack2(int i,int w){
	
	if(i==n)return 0;

	if(dp[i][w]!=-1)return dp[i][w];


	int profit1,profit2;

	if(w+weight[i] <= Cap)profit1 = value[i]+ knapsack2(i+1,w+weight[i]);
	else profit1=0;

	profit2=knapsack2(i+1,w);

	return dp[i][w]= max(profit1, profit2);
}

int main(){
	//READ;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>value[i]>>weight[i];
		}
		memset(dp,-1, sizeof(dp));
		cin>>Cap;
		cout<<knapsack2(0,0)<<endl;
}