#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define nline '\n';

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    bool sorted = true;
    for(int i=0;i<n-1;i++){
        if(s[i]-'0'>s[i+1]-'0'){
            sorted = false;
            break;
        }
    }
    if(sorted){
        cout<<0<<nline;
        return;
    }
    if(s.front()=='1'){
        int zero = 0;
        for(char c:s ){
            if(c=='0')zero++;
        }
        cout<<zero<<nline;
        return;
    }
    vector<long long>pref_o(n);
    for(int i=0;i<n;i++){
        if(i==0){
            pref_o[i]=(s[i]=='1');
        }else{
            pref_o[i]=pref_o[i-1]+(s[i]=='1');
        }
    }
    vector<long long>suf_z(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            suf_z[i]=(s[i]=='0');
        }else{
            suf_z[i]=suf_z[i+1]+(s[i]=='0');
        }
    }
    long long res = min(pref_o[n-1],suf_z[1]);
    for(int i=1;i<n-1;i++){
        res = min(res,pref_o[i]+suf_z[i+1]);
    }
    cout<<res<<nline;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
