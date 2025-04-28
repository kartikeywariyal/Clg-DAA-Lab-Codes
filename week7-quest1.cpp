#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>adj(n+1);
    int edges;
    cin>>edges;
    //assumuing the house of akshay is at node 1.
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<vector<int>>vec(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    vector<int>dist(n+1,INT_MAX);
    dist[1]=0;
    vec[1].push_back(1);
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        if(dist[node]<d)continue;
        for(auto &[to,w]:adj[node]){
            if(d+w<dist[to]){
                dist[to]=d+w;
                vec[to]=vec[node];
                vec[to].push_back(to);
                pq.push({d+w,to});
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<"Distance is: "<<dist[i]<<endl;
        cout<<"Shortest path is: ";
        for(int j=vec[i].size()-1;j>=0;j--){
            cout<<vec[i][j]<<' ';
        }
        cout<<endl;
    }
    
}
int main(){
    solve();
}
