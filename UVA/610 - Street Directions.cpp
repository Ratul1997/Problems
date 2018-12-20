///unsloved

#include <bits/stdc++.h>
#define null -1
using namespace std;

bool articulationPoint[1005],visited[1005],back_edges[1005][1005];
int low[1005],dist[1005], parent[1005];
int times=0;
vector<int> graph[1005];
vector<pair<int, int> >is_bridge;

void findBridge(int start){

	times = times+1;
	low[start] = dist[start] =times;
	visited[start] = true;
	int no_of_childern = 0;

	
	for(auto to : graph[start]){

		if(to == parent[start])continue;
		if(visited[to]){
			low[start] = min(low[start], dist[to]);
			back_edges[start][to]=true;
		}
		if(!visited[to]){

			++no_of_childern;
			parent[to] = start;
			findBridge(to);

			low[start]= min( low[start] , low[to] );

			if(dist[start] <= low[to]){
				back_edges[start][to]=true;
			}
		}
		
	}
}

void init(){
	for(int i=0;i<1005;i++){
		graph[i].clear();
		visited[i]=articulationPoint[i]=false;
		low[i]=dist[i]=0;
	}
	is_bridge.clear();
	memset(back_edges, 0 , sizeof(back_edges));
}
int main(){
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,edges,test=0;
	while(cin>>n>>edges ){
		
		if(n==0 && edges ==0 )break;
		init();
		
		while(edges--){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
			
		}
		for(int i=1 ;i<=n;i++){
			cout<<i<<"->";
			for(auto to: graph[i]){
				cout<<to<<" ";
			}
			cout<<endl;
		}

		for(int i=1;i<=n;i++){
			if(!visited[i])findBridge(i);
		}
		cout<<++test<<endl<<endl;
		for(int i=1 ;i<=n;i++){
			cout<<i<<"->";
			for(auto to: graph[i]){
				if(back_edges[i][to])cout<<to<<"(back_edges) ";
				else cout<<to<<" ";
			}
			cout<<endl;
		}
		for(int i=1; i<=n ;i++){
			for(auto to : graph[i]){
				if(!back_edges[i][to]){
					cout<<i<<" "<<to<<endl;
				}
			}
		}
		cout<<"#"<<endl;
	}
}
