#include <bits/stdc++.h>
#include <cstdio>
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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = 1 + dp[i + 1];
    if (i + a[i] < n) {
      dp[i] = min(dp[i], dp[i + a[i] + 1]);
    }
  }
  cout << dp[0] << "\n";
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
