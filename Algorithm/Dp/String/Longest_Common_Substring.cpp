#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){

	int dp[s1.size()+1][s2.size()+1];

	int result=0;

	for(int i=0;i<=s1.size();i++){
		for(int j=0; j<=s2.size(); j++){
			
			if(i==0 || j==0)dp[i][j]=0;
			else if(s1[i-1]==s2[j-1]) {
				dp[i][j]= dp[i-1][j-1]+1;
				result= max(result, dp[i][j]);
			}
			else {
				dp[i][j]= 0;
			}

		}
	}
	return result;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2)<<endl;
}