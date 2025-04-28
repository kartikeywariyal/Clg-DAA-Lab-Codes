#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>adj(n+1);
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        
    }
    vector<int>parent(n+1,-1);
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        if(mst[node])continue;
        mst[node]=true;
        for(auto &[to,w]:adj[node]){
            if(!mst[to] and w<key[to]){
                key[to]=w;
                parent[to]=node;
                pq.push({w,to});
            }
        }
    }
    cout<<"MST is: "<<endl;
    for(int i=2;i<=n;i++){
        cout<<"parent of "<<i<<" is "<<parent[i]<<endl;
    }
}
int main(){
    solve();
}
