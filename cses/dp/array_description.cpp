#include "bits/stdc++.h"
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (auto &y : x)
    cin >> y;
  vector<vector<int>> dp(n, vector<int>(m + 1));
  if (x[0] == 0) {
    for (int j = 1; j <= m; j++) {
      dp[0][j] = 1;
    }
  } else {
    dp[0][x[0]] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      for (int y : {j - 1, j, j + 1}) {
        if (1 <= y && y <= m) {
          if (x[i + 1] != 0 && x[i + 1] != y) {
            continue;
          }
          dp[i + 1][y] += dp[i][j];
          dp[i + 1][y] %= MOD;
        }
      }
    }
  }
  long long answer = 0;
  for (int i = 1; i <= m; i++) {
    answer += dp[n - 1][i];
    answer %= MOD;
  }
  cout << answer << "\n";
}
