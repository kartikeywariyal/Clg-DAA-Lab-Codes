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
  
  for(int i=0;i<n;i++){
    if(a[i]==key){
      cout<<"Element found at index "<<i<<endl;
      return;
    }
  }
  cout<<"Element not found\n";
}

int main(){
  int t;
  cin>>t;
  while(t--)
  solve();
}
