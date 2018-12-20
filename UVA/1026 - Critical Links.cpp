#include <bits/stdc++.h>
#define null -1
using namespace std;

bool articulationPoint[10005],visited[10005];
int low[10005],dist[10005], parent[10005];
int times=0;
vector<int> graph[10005];
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
		}
		if(!visited[to]){

			++no_of_childern;
			parent[to] = start;
			findBridge(to);

			low[start]= min( low[start] , low[to] );

			if(dist[start] < low[to] && parent[start] != null){
				(start<to)?is_bridge.push_back({start,to}):is_bridge.push_back({to,start});
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
	is_bridge.clear();
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,test=0,testt;
	cin>>testt;
	
	while(test<testt){
		cin>>n;
		int u,nodes, v;
		init();
		for(int i=0;i<n;i++){
			scanf("%d (%d)", &u,&nodes);

			while(nodes--){
				cin>>v;
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
		for(int i=0;i<n;i++){
			if(!visited[i])findBridge(i);
		}

		sort(is_bridge.begin(),is_bridge.end());
		printf("Case %d:\n",++test );
		cout<<is_bridge.size()<<" critical links"<<endl;
		for(int i=0;i<is_bridge.size();i++){
			cout<<is_bridge[i].first<<" - "<<is_bridge[i].second<<endl;
		}
	}
}
