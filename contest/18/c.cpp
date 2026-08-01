#include <algorithm>
#include <bits/stdc++.h>
#include <map>
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
  vector<int> a(2 * n + 1);
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  vector<ll> dp(2 * n + 1);
  map<int, int> first;
  for (int i = 1; i <= 2 * n; i++) {
    if (first.find(a[i]) == first.end()) {
      first[a[i]] = i;
      dp[i] = dp[i - 1] + 1;
    } else {
      ll l = 1LL * (i - first[a[i]] + 1) * (i - first[a[i]] + 1);
      dp[i] = max(dp[i - 1] + 1, dp[first[a[i]] - 1] + l);
    }
  }
  cout << dp[2 * n] << nline;
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
