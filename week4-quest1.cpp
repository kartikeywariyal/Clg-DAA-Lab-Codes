#include <bits/stdc++.h>
using namespace std;

int comparision=0,inversion=0;
void merge(int l,int mid,int r,vector<int>&a){
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int>c(n1),d(n2);
    for(int i=0;i<n1;i++){
        c[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        d[i]=a[mid+1+i];
    }
    int i=0,j=0,k=l;
    
    while(i<n1 and j<n2){
        comparision++;
        if(c[i]<=d[j]){
            a[k++]=c[i++];
        }
        else{
            inversion+=(n1-i);
            a[k++]=d[j++];
        }
    }
    
    while(i<n1){
        
        a[k++]=c[i++];
    }
    
    while(j<n2){
      
        a[k++]=d[j++];
    }
}
void mergeSort(int l,int r,vector<int>&a){
    if(l>=r)return;
    int mid=l+(r-l)/2;
    mergeSort(l,mid,a);
    mergeSort(mid+1,r,a);
    merge(l,mid,r,a);
    
    
}
void solve() {
    int n;
    comparision=0,inversion=0;
    cin>>n;
    vector<int>a(n);
    for(int &i:a)cin>>i;
    mergeSort(0,n-1,a);
    cout<<comparision<<endl;
    cout<<inversion<<endl;
   
}

int main() {
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
