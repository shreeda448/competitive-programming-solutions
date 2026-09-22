#include <bits/stdc++.h>
using namespace std;
#define nline '\n';

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    bool cont = false;
    for(int i=0;i<n-1;i++){
        if(s[i]=='0' && s[i+1]=='0'){
            cont=true;
            break;
        }
    }
    if(s.front()=='0'||cont){
        cout<<-1<<nline;
        return;
    }
    char cur = s.front();
    int ans = 1;
    int transition = 0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cur==s[i]){
            cnt++;
        }else{
            if(cnt%2==0){
                if((s[i]=='+' && s[i-1]=='-') || (s[i]=='-' && s[i-1]=='+')){
                    if(transition==1){
                        if(cnt==2){
                            ans=3;
                            break;
                        }else{
                            ans=2;
                        }
                    }else{
                       ans=2;
                      transition=1;
                    }
                }else{
                    ans=2;
                }
            }else{
                if((s[i]=='+' && s[i-1]=='-') || (s[i]=='-' && s[i-1]=='+')){
                        ans=2;
                        transition = 1;
                }else {
                    transition=0;
                }
            }
            cnt=1;
            cur=s[i];
        }
    }
    cout<<ans<<nline;
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
