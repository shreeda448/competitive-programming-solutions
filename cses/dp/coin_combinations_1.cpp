#include "bits/stdc++.h"
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &x : c)
    cin >> x;
  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < x; i++) {
    for (int coin : c) {
      if (i + coin <= x) {
        dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
      }
    }
  }
  cout << dp[x] << "\n";
  return 0;
}
