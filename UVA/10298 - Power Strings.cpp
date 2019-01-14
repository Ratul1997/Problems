#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
	return a>b;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	string s;
	while(cin>>s){
		if(s==".")break;

		int arr[26];
		memset(arr, 0 , sizeof(arr));
		arr[s[0]-'a']++;
		set<char>st(s.begin(),s.end());
		
		for(int i = 1 ; i< s.size();i++){
			if(s[i] != s[i-1] || st.size()==1)arr[s[i]-'a']++;

		}
		sort(arr,arr+26,compare);

		for(int i=0;i<25;i++){
			if(arr[i+1] == 0){
				cout<<arr[i]<<endl;
				break;
			}
		}

	}
}