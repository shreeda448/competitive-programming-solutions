#include <iostream>

using namespace std;

const int MAXN = 1000005;
long long ans[MAXN];
long long dp[3][1500];

void precompute() {
  int num = 1;
  for (int r = 1; r < 1500 && num <= 1000000; ++r) {
    int curr = r % 3;
    int prev1 = (r - 1) % 3;
    int prev2 = (r - 2) % 3;

    for (int c = 1; c <= r && num <= 1000000; ++c) {
      long long val = num;
      dp[curr][c] = val * val;

      if (r > 1) {
        if (c > 1)
          dp[curr][c] += dp[prev1][c - 1];
        if (c < r)
          dp[curr][c] += dp[prev1][c];
        if (c > 1 && c < r)
          dp[curr][c] -= dp[prev2][c - 1];
      }

      ans[num] = dp[curr][c];
      num++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
  }

  return 0;
}
