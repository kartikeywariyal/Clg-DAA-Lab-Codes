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
  
  int block1=0,block2=n-1;
  int comparison=0;
  for(int i=1;i<=n;i*=2){
    comparison++;
    if(a[i-1]==key){
      cout<<"Element found at index "<<i<<endl;
      cout<<comparison<<endl;
      return;
    }
    else if(a[i-1]<key)
    block1=i-1;
    else{
      block2=i-1;
      break;
    }
  }
  
  for(int i=block1;i<=block2;i++){
    comparison++;
    if(a[i]==key){
       cout<<"Element found at index "<<i<<endl;
      cout<<comparison<<endl;
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
