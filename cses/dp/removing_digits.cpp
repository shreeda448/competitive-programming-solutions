#include "bits/stdc++.h"
#include <vector>
using namespace std;

const int INF = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, INF);
  dp[n] = 0;
  for (int i = n; i >= 1; --i) {
    for (char c : to_string(i)) {
      int digit = c - '0';
      if (digit > 0) {
        dp[i - digit] = min(dp[i - digit], dp[i] + 1);
      }
    }
  }
  cout << dp[0] << "\n";
  return 0;
}
