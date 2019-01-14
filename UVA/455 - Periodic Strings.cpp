#include <bits/stdc++.h>
using namespace std;


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		for(int i= 1 ;i<=s.size(); i++){
			string substring = s.substr(0,i);
			

			string ss ;
			for(int j = 0 ; j< s.size()/i ;j++){
				ss+=substring;
			}
			if(ss == s){
				cout<<i<<endl;
				break;
			}
		}
		if(test)cout<<endl;
	}
}