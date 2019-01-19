#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
bool vis[100010];
int dist[100010];
vector<ii> v[100010];
int end_Node;
void dijkstra(int s,int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    memset(dist,-1,sizeof(dist));    
    memset(vis, false ,sizeof(vis));

    pq.push(ii(0, s));
    dist[s] = 0;
    while(!pq.empty())
    {
        ii from=pq.top();
        pq.pop();


        int d=from.first,u=from.second;
        
        vis[u] = true;
        if(u == end_Node)return;
        for(int i=0; i<v[u].size(); i++)
        {
            ii v2=v[u][i];
            if(!vis[v2.first]){
               
               if(dist[v2.first]==-1 || dist[u]+v2.second<dist[v2.first])
               {
                   dist[v2.first]=dist[u]+v2.second;
                   pq.push(ii(dist[v2.first],v2.first));
                   cout<<dist[v2.first]<<endl;
                   
               }   
           }
       }
   }
}
int main()
{
    freopen("input.txt","r", stdin);
    
    int nodes,edge, start, querry;

    while(cin>>nodes>>edge>>querry>>start){
        cout<<nodes<<" "<<edge<<" "<<querry<<" "<<start<<endl;
        for(int i=0; i<edge; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        vector<pair<int,int> > :: iterator it;
        for(int i=0; i<nodes; i++)
        {

            cout<<i<<" is connected with ";
            
            for(it=v[i].begin(); it!=v[i].end(); it++)
                cout<<it->first<<" "<<it->second<<" "<<endl;

            cout<<endl;
        }
        dijkstra(start,nodes);
        for(int i = 0 ;i<nodes; i++){

            cout<<"distance 1 to  -> "<<dist[i]<<endl;
        }
    }    
}
