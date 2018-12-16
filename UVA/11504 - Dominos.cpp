#include <bits/stdc++.h>
using namespace std;
vector<int>graph[100005],transpose[100005];
stack<int>st;
bool visit[100005];

void dfs(int start){
	visit[start]=true;

	for(auto to: graph[start]){
		if(!visit[to])dfs(to);
	}

	st.push(start);
}

void dfs_for_scc(int start){
	visit[start]=true;

	for(auto to: graph[start]){
		if(!visit[to])dfs_for_scc(to);
	}
}


int Kosarajus_algorithm(int n){
	memset(visit,false, sizeof(visit));

	for(int i=1;i<=n;i++){
		if(!visit[i])dfs(i);
	}
	
	memset(visit,false, sizeof(visit));

	int countt=0;
	while(!st.empty()){
		int start= st.top();
		st.pop();

		if(!visit[start]){
			dfs_for_scc(start);
			countt++;
		}
	}
	return countt;
}

int main(){
	int test;
	cin>>test;
	while(test--){
		for(int i=0;i<100005;i++){
			graph[i].clear();
			visit[i]=false;
		}

		int vertices,edges;
		cin>>vertices>>edges;

		while(edges--){
			int from,to;
			cin>>from>>to;

			graph[from].push_back(to);
		}
		cout<<Kosarajus_algorithm(vertices)<<endl;		
	}
}