#include<bits/stdc++.h>
#define GAP -2
#define MIS 0
#define MATCH 1
#define INF 1e10
using namespace std;


string child = "TTATTCTTGATTCGATATTGATTA";
string parent= "ATCAATCAGTTAGGGGATACATAT";
int DNA2(string parent , string child){
	int n = parent.size();
	int m = child.size();

	int temp[2][m+1];
	int maximum = -INF;
	
	int flag , previous;
	queue<int>q;
	for(int i=0 ; i<=n; i++){

		for(int j = 0; j<=m ;j++){
			
			if(i == 0 || j== 0){
				if(i == 0){	 
					q.push(j*GAP);
				}
				else if(j == 0 ){
					q.push(i*GAP);
					previous = i*GAP;
				}	
			}
			else{

				if(parent[i-1] == child[j-1]){
					int diag = q.front();
					q.pop();

					previous = diag+MATCH ;
					maximum = max(maximum , previous );
					q.push(previous);
				}
				else {
					int diag = q.front();
					q.pop();

					int vertical = q.front();
					int t =max( previous+GAP, max(diag+MIS , vertical+GAP));

					maximum = max(maximum , t);
					previous = t;
					q.push(t);
				}

				if(j == m){
					q.pop();
				}
			}
		}
	}
	while(!q.empty()){
		maximum = max(maximum, q.front());
		q.pop();
	}
	return maximum;
}
int DNA(int start , int end_number, int size ){
	
	//cout<<start<<" "<<end_number<<endl;
	
	string s(child.begin()+start, child.begin()+end_number+1);
	if(abs(end_number-start)<=10){
		cout<<s<<" "<<DNA2(parent, s )<<endl;
		return DNA2(parent, s);
	}
	
	int mid1 = (end_number+start)/3;

	return DNA(start, mid1, size)+DNA(mid1+1, end_number, size);
}


int main(){
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cout<<child.size()<<endl;
	cout<<DNA(0,child.size(), child.size()/3)<<endl;
	string s1,s2;
	    while(getline(cin,s1)&& getline(cin,s2))
	    {
	        cout<<DNA2(s1,s2)<<endl;
	        s1.clear();
	        s2.clear();
	    }

}