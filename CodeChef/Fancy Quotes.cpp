#include<bits/stdc++.h>
using namespace std;
int main(){
	//sfreopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		getchar();
		string s;
		getline(cin,s);
		cout<<s<<endl;
		size_t found = s.find("not");

		if (found!=std::string::npos){
			if((s[found-1]>= 'a' && s[found-1]<= 'z' ) || (s[found+3]>= 'a' && s[found+3]<= 'z' )){
			   cout<<"regularly fancy"<<endl;	
			}
			else{
				cout<<"Real Fancy"<<endl;
			}
		}
		else{
			cout<<"regularly fancy"<<endl;
		}
	}
}