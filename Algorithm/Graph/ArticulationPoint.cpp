#include <bits/stdc++.h>
#define null -1
using namespace std;

bool articulationPoint[1005],visited[1005];
int low[1005],dist[1005], parent[1005];
int times=0;
vector<int> graph[1005];

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


int main(){
	///freopen("input.txt","r",stdin);

	int vertice, edges;
	cin>>vertice>>edges;



	for(int i=0 ;i<edges; i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(parent, -1, sizeof(parent));
	findArticulationPoint(1);

	for(int i=1;i<= vertice; i++){
		if(articulationPoint[i]){
			cout<<i<<" ";
		}
	}
}
/*
input file 
vertex edges
u to v
7 7
1 2
1 3
3 4
3 7
4 5
4 6
6 7
*/
