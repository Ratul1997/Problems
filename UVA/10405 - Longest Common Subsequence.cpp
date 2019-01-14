#include<bits/stdc++.h>
#define GAP -2
#define MIS 0
#define MATCH 1
#define INF 1e10
using namespace std;

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
					q.push(0);
				}
				else if(j == 0 ){
					q.push(0);
					previous = i*GAP;
				}	
			}
			else{

				if(parent[i-1] == child[j-1]){
					int diag = q.front();
					q.pop();

					previous = diag+1 ;
					q.push(previous);
				}
				else {
					int diag = q.front();
					q.pop();

					int vertical = q.front();
					int t =max(previous, vertical);

					previous = t;
					q.push(t);
				}

				if(j == m){
					q.pop();
				}
			}
		}
	}

	return q.back();
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s1,s2;
	    while(getline(cin,s1)&& getline(cin,s2))
	    {
	        cout<<DNA2(s1,s2)<<endl;
	        s1.clear();
	        s2.clear();
	    }

}