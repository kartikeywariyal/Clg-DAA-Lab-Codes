#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>>adj(n+1);
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        
    }

    vector<vector<int>>dist(n+1,vector<int>(k+1,INT_MAX));
    int src,dest;
    cin>>src>>dest;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    pq.push({0,src,0});
    dist[src][0]=0;
    while(!pq.empty()){
        auto [total,node,d]=pq.top();
        pq.pop();
        if(dist[node][d]<total){
            continue;
        }
        for(auto &[to,w]:adj[node]){
            if(d+1<=k and total+w<dist[to][d+1]){
                dist[to][d+1]=total+w;
                pq.push({total+w,to,d+1});
            }
        }
    }
    if(dist[dest][k]==INT_MAX){
        cout<<"No path found!!!"<<endl;
    }
    else{
        cout<<"Shortest path from "<<src<<" to "<<dest<<" in exactly k edges is: "<<dist[dest][k]<<endl;
    }
    
}
int main(){
    solve();
}
