#include <bits/stdc++.h>
using namespace std;
vector<int>graph[1000],transpose[1000];
stack<int>st;
bool visit[1000];

void make_transpose(int n){

	for(int i=0;i<n;i++){
		for(auto to: graph[i]){
			transpose[to].push_back(i);
		}
	}

}

void dfs(int start){
	visit[start]=true;
	
	for(auto to: graph[start]){
		if(!visit[to])dfs(to);
	}

	st.push(start);
}

void dfs_for_scc(int start){
	visit[start]=true;
	cout<<start<<" ";

	for(auto to: transpose[start]){
		if(!visit[to])dfs_for_scc(to);
	}
}


void Kosarajus_algorithm(int n){
	memset(visit,false, sizeof(visit));

	for(int i=0;i<n;i++){
		if(!visit[i])dfs(i);
	}
	make_transpose(n);

	memset(visit,false, sizeof(visit));

	while(!st.empty()){
		int start= st.top();
		st.pop();
		cout<<"Stack : "<<start<<endl;

		if(!visit[start]){
			dfs_for_scc(start);
		}
		cout<<endl;
	}
}

int main(){
	int vertices,edges;
	cin>>vertices>>edges;

	while(edges--){
		int from,to;
		cin>>from>>to;

		graph[from].push_back(to);
	}
	Kosarajus_algorithm(vertices);

}
/*

**input 

5 5

1 0
0 2
2 1
0 3
3 4
*/