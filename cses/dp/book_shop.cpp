#include "bits/stdc++.h"
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n);
  vector<int> s(n);
  for (auto &x : h)
    cin >> x;
  for (auto &x : s)
    cin >> x;
  vector<long long> dp(x + 1, 0);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = x - 1; j >= 0; j--) {
      if (h[i] + j <= x) {
        dp[h[i] + j] = max(dp[h[i] + j], dp[j] + s[i]);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
  return 0;
}
