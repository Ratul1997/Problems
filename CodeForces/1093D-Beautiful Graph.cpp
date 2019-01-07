#include <bits/stdc++.h>
#define MOD 998244353
#define MAX int(3e5) + 999
using namespace std;
vector<int>graph[MAX];
bool visit[MAX];
int color[MAX];
int col[2];
long long powr[MAX];
int k;
void dfs(int source){

	visit[source] = true;
	col[color[source]]++;
	for(auto to: graph[source]){

		if(!visit[to] ){
			color[to]= color[source]==1 ? 0:1;
			visit[to]= true;
			dfs(to);
		}
		else if(color[to] == color[source]){k=1;return ;}
	}
	return ;
}

void init(){
	for(int i=0;i<=MAX ;i++)graph[i].clear();

	memset(visit,false,sizeof(visit));
	memset(color, 0 , sizeof(color));	
}
int power(){
	powr[0] = 1LL;
	for(long long i=1; i<300005 ;i++)powr[i] = (2*powr[i-1])%MOD;
}
int main(){
	//freopen("input.txt","r", stdin);
	//freopen("output.txt","w",stdout);
	power();
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		init();

		while(m--){
			int u,v;
			cin>> u>> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		long long result = 1;
		for(int i=1 ;i<=n; i++){
			k=0;
			col[0]=col[1]=0;
			if(!visit[i]){
				dfs(i);
				if(k==1){
					result = result*0;
				}
				else{
			//		cout<<col[0]<<" "<<col[1]<<endl;

					long long s = (powr[col[0]]%MOD + powr[col[1]]%MOD)%MOD;
					result = (result%MOD * s%MOD)%MOD;
				}
			}
		}
		cout<<result<<endl;
	}
}