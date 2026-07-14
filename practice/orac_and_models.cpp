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
  vector<ll> s(n);
  for (auto &x : s)
    cin >> x;
  vector<ll> dp(n + 1, 1);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        if (s[i - 1] > s[j - 1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
        if (i != 1) {
          if (s[i - 1] > s[(i / j) - 1]) {
            dp[i] = max(dp[i], dp[i / j] + 1);
          }
        }
      }
    }
  }
  ll maxi = 0;
  for (auto x : dp) {
    maxi = max(maxi, x);
  }
  cout << maxi << nline;
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
