#include<bits/stdc++.h>
#define GAP -2
#define MIS 0
#define MATCH 1
#define INF 1e10
using namespace std;


string child = "abca";
string parent= "abdcad";
int temporary ;
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
			//showQueue(q);
		}
    showQueue(q);
	}

	return q.back();
}
int check(string parent, string child){

	//cout<<parent<<" "<<child<<" ";
	int j =0,i;
	for( i= temporary ;i<parent.size() && j<child.size(); i++){

        cout<<parent[i];
		if(parent[i] == child[j] ){
	//		cout<<i<<" "<<j<<" ";
	//		cout<<child[j];
			temporary = i;
			j++;
		}
	}
	cout<<endl;
	//cout<<"  j = "<<j<<" "<<temporary<<endl;
	return j;
}
int DNA(int start , int end_number){

	//cout<<start<<" "<<end_number<<endl;

	string s(child.begin()+start, child.begin()+end_number+1);
	if(abs(end_number-start)<=4){
		string pr(parent.begin()+temporary , parent.end());

		return check(parent, s );
	}

	int mid1 = (end_number+start)/2;

	return DNA(start, mid1)+DNA(mid1+1, end_number);
}


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//cout<<child.size()<<endl;
	cout<<DNA2(parent, child)<<endl;
	//cout<<DNA(0,child.size())<<endl;

}
