#include <bits/stdc++.h>
#define cover(x,y) memset(x,y, sizeof(x)) 

using namespace std;


map <int,int> visited,vis,dist;
map<int, vector< int > >graph;

int bfs(int start,int last){
	
	int countt=1;
	queue<int> q;
	q.push(start);
	dist[start]=0;
	vis[start]=1;
	while(!q.empty()){
		int from=q.front();
		q.pop();
		for(auto to : graph[from]){
			if(vis[to]==0){
				q.push(to);
				dist[to]= dist[from]+1;
				vis[to]=1;
				if(dist[from]<last) countt++;
			}
		}
	}
	return countt;
}
void init(){
	graph.clear();
	visited.clear();
}
int main()
{

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=0, n;
	while(cin>>n && n!=0){
		init();
		int u,v,cnt=0;

		for(int i=0;i<n;i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
			if(!visited[u]) cnt++;
			if(!visited[v]) cnt++;
			if(!visited[u] && u==v) cnt--;
			visited[u]=visited[v]=1;
		}
		int start,last;

		while(cin>>start>>last ){

			if(start == 0 && last ==0)break;
			int ans=0;
			if(visited[start]==1){
				vis.clear();
				ans=bfs(start,last);

			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++t,cnt-ans,start,last);
			dist.clear();
		}
	}
}