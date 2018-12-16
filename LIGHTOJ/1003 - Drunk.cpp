///UNSOLVED


#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10005];


bool kahns_algorithm(int n){
	
	vector<int>indegree(n,0);
	
	//counting indegree
	for(int i=0;i<n;i++){
		for(auto to : graph[i]){
			indegree[to]++;
		}
	}

	queue<int>q;

	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	vector<int> topsort_order;

	int countt=0;
	while(!q.empty()){
		int from = q.front();
		q.pop();
		topsort_order.push_back(from);

		for(auto to : graph[from]){
			if(--indegree[to]==0){
				q.push(to);
			}
			countt++;
		}
	}
	cout<<countt<<endl;
	if(countt != n){
		return false;
	}
	return true;
}

int main(){

	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		int vertices,edges;
		cin>>edges;
		
		map<string,int>mp;
		int cnt=0;
		while(edges--){
			string from,to;
			cin>>from>>to;
			if(!mp[from])mp[from]=cnt++;
			if(!mp[to])mp[to]=cnt++;

			graph[mp[from]].push_back(mp[to]);
		}
		cout<<cnt<<endl;
		printf("Case %d: ", t);
		
		puts(kahns_algorithm(cnt)?"Yes": "No");
	}
}
