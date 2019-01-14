#include<bits/stdc++.h>
#define GAP -2
#define MIS 0
#define MATCH 1
#define INF 1e10
using namespace std;

int Dna(string parent, string child){
	
	int n = parent.size();
	int m = child.size();

	int temp[n+1][m+1];
	for(int i = 0 ; i<=m ;i++){
		temp[0][i] = i*GAP;  
	}
	for(int i = 0 ; i<=n ;i++){
		temp[i][0] = i*GAP;  
	}

	int flag = 0;
	for(int i=1 ; i<=n; i++){

		for(int j = 1; j<=m ;j++){
			if(parent[i-1] == child[j-1]){
				temp[i][j] = temp[i-1][j-1]+1;
			}
			else {
				temp[i][j] =max( temp[i][j-1]+GAP, max(temp[i-1][j-1]+MIS , temp[i-1][j]+GAP));
			}
		}
	}

	for(int i = 0 ;i<= n; i++){
		for(int j= 0 ;j<=m;j++){
			cout<<temp[i][j]<<" ";
		}
		cout<<endl;
	}
}

void DNA(string parent , string child){
	int n = parent.size();
	int m = child.size();

	int temp[2][m+1];
	
	int flag ;
	for(int i=0 ; i<=n; i++){

		flag = i & 1;

		for(int j = 0; j<=m ;j++){
			if(i == 0 || j== 0){
				if(i == 0){
					temp[flag][j] = j*GAP;	
				}
				else if(j == 0 ){
					temp[flag][j] = i*GAP;
				}
				cout<<temp[flag][j]<<" ";	
			}
			else if(parent[i-1] == child[j-1]){
				temp[flag][j] = temp[1-flag][j-1]+1;
				cout<<temp[flag][j]<<" ";	

			}
			else {
				temp[flag][j] =max( temp[flag][j-1]+GAP, max(temp[1-flag][j-1]+MIS , temp[1 - flag][j]+GAP));
				cout<<temp[flag][j]<<" ";	
			}

		}
		cout<<endl;
	}

}
void showQueue(queue<int>pq){
	while(!pq.empty()){
		cout<<pq.front()<<" ";
		pq.pop();
	}
	cout<<endl;
}
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
		showQueue(q);
	}
	while(!q.empty()){
		maximum = max(maximum, q.front());
		q.pop();
	}
	return maximum;
}

int main(){
	string parent = "ATCGAATTTCAGGATCCGGATCGATCG";
	string child = "TC";

	//Dna(parent, child);
	//DNA(parent, child);
	cout<<DNA2(parent, child)<<endl;

}