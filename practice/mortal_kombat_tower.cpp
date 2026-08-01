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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(2, 1e9));
  dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i]);
    if (i >= 2) {
      dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[i - 1] + a[i]);
    }
    dp[i][1] = min(dp[i][1], dp[i - 1][0]);
    if (i >= 2) {
      dp[i][1] = min(dp[i][1], dp[i - 2][0]);
    }
  }
  cout << min(dp[n][0], dp[n][1]) << nline;
  return;
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
