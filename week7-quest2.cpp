#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>adj(n+1);
    int edges;
    cin>>edges;
    vector<vector<int>>ok;
    //assumuing the house of akshay is at node 1.
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        ok.push_back({u,v,w});
    }
    vector<vector<int>>vec(n+1);
    vector<int>dist(n+1,INT_MAX);
    dist[1]=0;
    //assuming the graph doesnt have any negative weights
    vec[1].push_back(1);
    for(int i=1;i<=n;i++){
        for(auto &e:ok){
            int u=e[0],v=e[1],w=e[2];
            if(dist[u]+w<dist[v]){
                vec[v]=vec[u];
                vec[v].push_back(v);
                dist[v]=dist[u]+w;
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
