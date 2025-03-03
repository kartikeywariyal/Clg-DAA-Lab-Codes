#include<bits/stdc++.h>
using namespace std;

int check(vector<int>&a,int key,int i){
    int l=i+1,r=a.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]==key)return mid;
        if(a[mid]<key)l=mid+1;
        else r=mid-1;
    }
    return -1;
}
void solve(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int &i:a)cin>>i;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int diff=target-a[i];
        int index=check(a,diff,i);
        if(index!=-1){
            cout<<a[i]<<' '<<a[index]<<endl;
            return;
        }
    }
    cout<<"No such element found\n";

}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
