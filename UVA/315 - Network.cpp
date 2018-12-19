#include <bits/stdc++.h>
#define null -1
using namespace std;

bool articulationPoint[105],visited[105];
int low[105],dist[105], parent[105];
int times=0;
vector<int> graph[105];

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

			if(dist[start] <= low[to] && parent[start] != null){
				articulationPoint[start]=true;
			}
		}
		
	}
}

void init(){
	for(int i=0;i<105;i++){
		graph[i].clear();
		visited[i]=articulationPoint[i]=false;
		low[i]=dist[i]=0;
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int u,v,N;
	string s;

	while(cin>>N){
		if(N==0) break;
		init();

		getchar();
		while(getline(cin,s)){
			
			istringstream is(s);

			is>>u;
			if(u==0) break;

			while(is>>v){
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		memset(parent, -1, sizeof(parent));
		findArticulationPoint(1);
		int countt=0;
		for(int i=1;i<= N; i++){
			if(articulationPoint[i]){
				countt++;
			}
		}
		cout<<countt<<endl;
	}
}
