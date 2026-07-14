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

const int INF = 1e9 + 5;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &x : c)
    cin >> x;
  vector<int> dp(x + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < x; i++) {
    for (int coin : c) {
      if (i + coin <= x) {
        dp[i + coin] = min(dp[i + coin], dp[i] + 1);
      }
    }
  }
  if (dp[x] == INF) {
    cout << -1 << nline;
    return;
  }
  cout << dp[x] << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
