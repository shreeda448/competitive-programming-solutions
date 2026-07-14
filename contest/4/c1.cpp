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

void solve() {
  int n, x, s;
  cin >> n >> x >> s;
  string u;
  cin >> u;
  vector<int> dp(x + 1, -1);
  dp[x] = 0;
  for (char c : u) {
    vector<int> next_dp = dp;
    for (int e = 0; e < x + 1; e++) {
      if (dp[e] == -1)
        continue;
      int remaining = (x - e) * s - dp[e];
      if (c == 'I') {
        if (e > 0) {
          if (dp[e] + 1 > next_dp[e - 1]) {
            next_dp[e - 1] = dp[e] + 1;
          }
        }
      } else if (c == 'E') {
        if (x - e > 0) {
          if (dp[e] + 1 > next_dp[e]) {
            next_dp[e - 1] = dp[e] + 1;
          }
        }
      }
    }
  }
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
