#include "bits/stdc++.h"
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));

  dp[1][1] = grid[0][0] == '.' ? 1 : 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i - 1][j - 1] == '.') {
        dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[n][n] << "\n";
  return 0;
}
