#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

const int MOD = 1e8;

// dp[footmen_used][horsemen_used][last_type][streak]
//  basecase if footmen_used = 0 or horsemen_used = 0
//  then  dp[footmen_used][horsemen_used][last_type][streak]=1;
//  transition
//  if last_type = footmen {
//      if streak<k1 && footmen_used<n1{
//          dp[footmen_used][horsemen_used][last_type][streak]->
//          dp[footmen_used+1][horsemen_used][footmen][streak+1]
//      }else {
//          dp[footmen_used][horsemen_used][last_type][streak]->
//          dp[footmen_used][horsemen_used+1][footmen][1]
//      }
//  }else{
//      if streak<k2 && horsemen_used<n2 {
//          dp[footmen_used][horsemen_used][last_type][streak]->
//          dp[footmen_used+1][horsemen_used][horsemen_used][1]
//      }else{
//          dp[footmen_used][horsemen_used][last_type][streak]->
//          dp[footmen_used][horsemen_used+1][horsemen_used][streak+1]
//      }
//  }
//  my answer will be  the sum of all dp[n1][n2]'s

void solve() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  vector<vector<vector<vector<ll>>>> dp(
      n1 + 1, vector<vector<vector<ll>>>(
                  n2 + 1, vector<vector<ll>>(2, vector<ll>(15))));

  dp[0][0][0][0] = 1;

  for (int footmen_used = 0; footmen_used <= n1; footmen_used++) {
    for (int horsemen_used = 0; horsemen_used <= n2; horsemen_used++) {
      for (int last_type = 0; last_type < 2; last_type++) {
        int size = last_type == 0 ? k1 : k2;
        for (int streak = 0; streak <= size; streak++) {
          ll current_val = dp[footmen_used][horsemen_used][last_type][streak];
          if (current_val == 0)
            continue;
          if (last_type == 0) {
            if (streak < k1 && footmen_used < n1) {
              dp[footmen_used + 1][horsemen_used][0][streak + 1] =
                  (dp[footmen_used + 1][horsemen_used][0][streak + 1] +
                   current_val) %
                  MOD;
            }
            if (horsemen_used < n2) {
              dp[footmen_used][horsemen_used + 1][1][1] =
                  (dp[footmen_used][horsemen_used + 1][1][1] + current_val) %
                  MOD;
            }
          } else {
            if (footmen_used < n1) {
              dp[footmen_used + 1][horsemen_used][0][1] =
                  (dp[footmen_used + 1][horsemen_used][0][1] + current_val) %
                  MOD;
            }
            if (streak < k2 && horsemen_used < n2) {
              dp[footmen_used][horsemen_used + 1][1][streak + 1] =
                  (dp[footmen_used][horsemen_used + 1][1][streak + 1] +
                   current_val) %
                  MOD;
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int last_type = 0; last_type < 2; last_type++) {
    int size = last_type == 0 ? k1 : k2;
    for (int streak = 0; streak <= size; streak++) {
      ans += dp[n1][n2][last_type][streak];
      ans %= MOD;
    }
  }
  cout << ans << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
