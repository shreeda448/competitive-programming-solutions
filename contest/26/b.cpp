#include "bits/stdc++.h"
using namespace std;
#define nline '\n';

void solve(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long res = 0;
    if(a>=b){
        res= a-b+c;
    }
    if(a<b){
        res = max(b-a,c+a-b);
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
