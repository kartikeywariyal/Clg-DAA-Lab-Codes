#include<iostream>
#include<vector>

using namespace std;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int &i:a)cin>>i;
  int key;
  cin>>key;
  
  int l=0,r=n-1;
  int ans=0;
  int comparison=0;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(a[mid]>=key){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
    comparison++;
  }
  if(a[ans]==key){
    cout<<"Element found at index "<<ans<<endl;
    cout<<"comparison are : "<<comparison<<endl;
    return;
  }
  cout<<"ELement not found\n";
}

int main(){
  int t;
  cin>>t;
  while(t--)
  solve();
}
