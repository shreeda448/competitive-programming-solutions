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
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i + j <= n) {
        dp[i + j] = (dp[i + j] + dp[i]) % MOD;
      }
    }
  }
  cout << dp[n] << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
