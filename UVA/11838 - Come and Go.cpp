#include <bits/stdc++.h>

using namespace std;
vector<int>graph[20005],transpose[20005];
stack<int>st;
bool visit[20005];

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

	for(auto to: transpose[start]){
		if(!visit[to])dfs_for_scc(to);
	}
}


int Kosarajus_algorithm(int n){
	memset(visit,false, sizeof(visit));

	for(int i=0;i<n;i++){
		if(!visit[i])dfs(i);
	}
	make_transpose(n);

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

void init(){
	for(int i=0;i<20005;i++){
		graph[i].clear(),transpose[i].clear(),visit[i]=false;
	}
}
int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int vertices,edges;
	while(cin>>vertices>>edges && vertices!=0 && edges!=0){
		init();
		while(edges--){
			int from,to,p;
			cin>>from>>to>>p;

			graph[from-1].push_back(to-1);
			if(p==2)graph[to-1].push_back(from-1);
		}
		Kosarajus_algorithm(vertices)==1 ? cout<<1: cout<<0;

		cout<<endl;
	}
}