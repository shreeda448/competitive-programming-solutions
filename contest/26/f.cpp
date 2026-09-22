#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define nline '\n';

void solve(){
    int n;cin>>n;
    long long mx = 0;
    long long z = 0;
    for(int i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        mx = max(mx,x);
        z+= y;
    }
    long long ans = 0;
    long long ms = 0;
    long long temp = z*n;
    for(int i = 0;i<=temp;i++){
            if(z>=i){
                z-=i;
                ms = i;
            }else{
                ans=i;
                break;
            }
    }
    if(ms == mx){
        mx++;
    }
    cout<<max(ans,mx)<<nline;
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
