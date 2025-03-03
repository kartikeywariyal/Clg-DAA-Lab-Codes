#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    char d=' ';
    int max1=-1;
    for(int i=0;i<26;i++){
        if(max1<freq[i]){
            max1=freq[i];
            d=(char)('a'+i);
        }
    }
    cout<<"Character "<<d<<" has the max frequency of "<<max1<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
