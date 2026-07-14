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

// bool dp[sum]
// dp[0] = true
// for all u from 1 to k except x
// if dp[i] = true then dp[i+u] = true

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<pair<bool, vector<int>>> dp(n + 1, {false, vector<int>(k)});
  dp[0] = {true, vector<int>(k, 0)};
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j != x && dp[i].first) {
        if (i + j <= n) {
          dp[i + j].first = true;
          dp[i + j].second = dp[i].second;
          dp[i + j].second[j - 1]++;
        }
      }
    }
  }
  if (dp[n].first) {
    cout << "YES" << nline;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      ans += dp[n].second[i];
    }
    cout << ans << nline;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < dp[n].second[i]; j++) {
        cout << i + 1 << " ";
      }
    }
    cout << nline;
  } else {
    cout << "NO" << nline;
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
