//unsolved

#include <bits/stdc++.h>

#define null -1
using namespace std;

int articulationPoint[10005];
bool visited[10005];
int low[10005],dist[10005], parent[10005];
int times=0;
vector<int> graph[10005];
int no_of_childern = 0,root;

void findArticulationPoint(int start){

	times = times+1;
	low[start] = dist[start] =times;
	visited[start] = true;
	

	
	for(auto to : graph[start]){

		if(to == parent[start])continue;
		if(visited[to]){
			low[start] = min(low[start], dist[to]);
		}
		if(!visited[to]){

			if(start ==  root)++no_of_childern;

			parent[to] = start;
			findArticulationPoint(to);

			low[start]= min( low[start] , low[to] );

			if(dist[start] <= low[to]){
				++articulationPoint[start];
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
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int u,v,N,m;	
	string s;

	while(cin>>N>>m){
		if(N==0 && m==0) break;
		init();

		while(cin>>u>>v){
			if(u==-1 && v==-1)break;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		memset(parent, -1, sizeof(parent));
		for(int i=0;i< N; i++){
			if(!visited[i]){
				root = i;
				findArticulationPoint(1);
		        articulationPoint[i] = (no_of_childern>1);
			}
		}
		vector<pair<int,int> > vect;
		for(int i=0 ;i<N ;i++){
			vect.push_back({articulationPoint[i]+1 , i});
			cout<<i<<" "<<articulationPoint[i]<<endl;
		}

		for(int j=1,i=0;j<= m && i<vect.size();i++,j++){
			cout<<vect[i].second<<" "<<vect[i].first;
		}
	}
}
