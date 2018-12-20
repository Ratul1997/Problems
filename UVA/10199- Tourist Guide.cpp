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
	int N,test=0;
	bool space= false;
	

	while(cin>>N){
		if(N==0) break;
		init();
		map<string, int>mp;
		map<int,string>mp2;

		int cnt=0;
		for(int i=0;i<N;i++){
			string s;
			cin>>s;
			if(!mp[s])mp[s]=++cnt;

			mp2[cnt]=s;

		}
		int edges;
		cin>>edges;
		while(edges--){

			string s1,s2;
			cin>>s1>>s2;
			graph[mp[s1]].push_back(mp[s2]);
			graph[mp[s2]].push_back(mp[s1]);
			
		}

		memset(parent, -1, sizeof(parent));
		for(int i=1;i<=N;i++){
			if(!visited[i]){
				findArticulationPoint(i);
			}
		}
		if(space)cout<<endl;

		space=true;
		
		int countt=0;
		vector<string>towns;
		for(int i=1;i<= N; i++){
			if(articulationPoint[i]){
				towns.push_back(mp2[i]);
				countt++;
			}
		}
		printf("City map #%d: %d camera(s) found\n",++test, countt );
		sort(towns.begin(),towns.end());
		for(int i=0;i<towns.size();i++)cout<<towns[i]<<endl;

			
	}
}
