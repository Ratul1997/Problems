#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) 
{ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    vector<int> result(n1 + n2, 0); 
   
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        i_n2 = 0;  
           
        for (int j=n2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
   
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            carry = sum/10; 
   
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        i_n1++; 
    } 
   
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    if (i == -1) 
    return "0"; 
   
    string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
} 

string maximum(string a, string b){
	if(a[0] == '-')return b;
	else if(b[0] == '-') return a;
	else if(a.size()> b.size()) return a;
	else if(a.size()< b.size())return b;
	else{
		for(int i=0 ;i<a.size();i++){
			if(a[i]>b[i])return a;
			if(a[i]<b[i]){
				return b;
			}
		}
	}
	return a;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int n,count = 0;
    while(cin>>n){
		count = 0;
		int arr[205];
		arr[++count] = n;
		while(cin>>n){
			if(n == -999999)break;
			arr[++count] = n;
		}

		string mul = "1",ans = "-999999";
		for(int i = 1 ;i<=count;i++){
			mul = "1";
			for(int j= i; j<=count;j++){
				string num = to_string(arr[j]);

				if((num[0] != '-' && mul[0] == '-')){
					string s(mul.begin()+1, mul.end());
					
					mul ="-"+multiply(s, num);

				}
				else if((num[0] == '-' && mul[0] != '-')){
					string s(num.begin()+1, num.end());
					
					mul = "-"+multiply(s, mul);

				}
				else if((num[0] == '-' && mul[0] == '-')){
					string s(num.begin()+1, num.end());
					string s2(mul.begin()+1, mul.end());
					
					mul=multiply(s, s2);
				}
				else{
					mul = multiply(mul,num);
				}
				ans = maximum(ans, mul);

			}
		}
		cout<<ans<<endl;
	}
}