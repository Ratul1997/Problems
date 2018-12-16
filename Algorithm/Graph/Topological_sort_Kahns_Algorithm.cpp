#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10005];


void kahns_algorithm(int n){
	
	vector<int>indegree(n,0);
	
	//counting indegree
	for(int i=0;i<n;i++){
		for(auto to : graph[i]){
			indegree[to]++;
		}
	}

	queue<int>q;

	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	vector<int> topsort_order;

	int countt=0;
	while(!q.empty()){
		int from = q.front();
		q.pop();
		topsort_order.push_back(from);

		for(auto to : graph[from]){
			if(--indegree[to]==0){
				q.push(to);
			}
			countt++;
		}
	}
	if(countt != n){
		cout<<"There is a cycle"<<endl;
		return;
	}

	for(int i=0;i<topsort_order.size();i++){
		cout<<topsort_order[i]<<" ";
	}
	cout<<endl;
	return;
}

int main(){

	int vertices,edges;
	cin>>vertices>>edges;

	while(edges--){
		int from,to;
		cin>>from>>to;

		graph[from].push_back(to);
	}
	kahns_algorithm(vertices);
}

/*
input 

6 6

5 2
5 0
4 0
4 1
2 3
3 1
*/