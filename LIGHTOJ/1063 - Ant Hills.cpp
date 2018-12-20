#include <bits/stdc++.h>
#define null -1
using namespace std;

bool articulationPoint[10005],visited[10005];
int low[10005],dist[10005], parent[10005];
int times=0;
vector<int> graph[10005];

void findArticulationPoint(int start){

	times = times+1;
	low[start] = dist[start] =times;
	visited[start] = true;
	int no_of_childern = 0;

	
	for(auto to : graph[start]){

		if(to == parent[start])continue;
		if(visited[to]){
			low[start] = min(low[start], dist[to]);
		}
		if(!visited[to]){

			++no_of_childern;
			parent[to] = start;
			findArticulationPoint(to);

			low[start]= min( low[start] , low[to] );

			if(no_of_childern>1 && parent[start] ==  null){
				articulationPoint[start] = true;
			}


			// for bridge dist[start] < low[to]

			if(dist[start] <= low[to] && parent[start] != null){
				articulationPoint[start]=true;
			}
		}
		
	}
}

void init(){
	for(int i=0;i<10005;i++){
		graph[i].clear();
		visited[i]=articulationPoint[i]=false;
		low[i]=dist[i]=0;
	}
}

int main(){
	///freopen("input.txt","r",stdin);

	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		init();
		int vertice, edges;
		cin>>vertice>>edges;

		for(int i=0 ;i<edges; i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(parent, -1, sizeof(parent));
		for (int i = 1; i <= vertice; ++i)
		{
			if(!visited[i]){
				findArticulationPoint(i);
			}
		}

		int countt=0;
		for(int i=1;i<= vertice; i++){
			if(articulationPoint[i]){
				countt++;
			}
		}
		printf("Case %d: %d\n",t,countt );
	}
}