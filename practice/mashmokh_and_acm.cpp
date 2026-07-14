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

const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(k + 1);
  for (int i = 0; i <= k; i++) {
    dp[i].resize(n + 1);
  }
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1;
  }
  for (int i = 1; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = 1; p <= n; p++) {
        if (j * p > n) {
          break;
        }
        dp[i + 1][j * p] += dp[i][j];

        dp[i + 1][j * p] %= MOD;
      }
    }
  }
  ll ans = 0;
  for (auto x : dp[k]) {
    ans += x;
    ans %= MOD;
  }
  cout << ans % MOD << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
