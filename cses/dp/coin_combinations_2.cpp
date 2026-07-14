#include "bits/stdc++.h"
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &g : c)
    cin >> g;
  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int coin : c) {
    for (int s = 0; s < x; s++) {
      if (coin + s <= x) {
        dp[s + coin] = (dp[s + coin] + dp[s]) % MOD;
      }
    }
  }
  cout << dp[x] << "\n";
  return 0;
}
