#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &i:a)cin>>i;
    int compare=0,shifts=0;

    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=a[i];
        compare++;

        while(j>=0 and a[j]>key){
            shifts++;
            a[j+1]=a[j];
            j--;
            compare++;
        }
        a[j+1]=key;

    }
    for(int i:a)cout<<i<<' ';
    cout<<endl;
    cout<<"Compare is: "<<' '<<compare<<endl;
    cout<<"Total Shifts is: "<<shifts<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
