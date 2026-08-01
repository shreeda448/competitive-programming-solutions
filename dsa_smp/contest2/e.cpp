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

const int MOD = 1e9 + 7;

void solve() {
  int r, g;
  cin >> r >> g;
  int h = 0;
  while ((long long)(h + 1) * (h + 2) / 2 <= r + g) {
    h++;
  }
  if (h == 0) {
    cout << 0 << "\n";
    return;
  }
  vector<vector<int>> dp(2, vector<int>(r + 1, 0));
  dp[0][0] = 1;
  long long total_blocks = 0;
  for (int i = 1; i <= h; i++) {
    int curr = i & 1;
    int prev = curr ^ 1;
    for (int x = 0; x <= r; x++) {
      dp[curr][x] = 0;
    }
    total_blocks += i;
    for (int x = 0; x <= r; x++) {
      if (dp[prev][x] == 0)
        continue;
      if (x + i <= r) {
        dp[curr][x + i] = (dp[curr][x + i] + dp[prev][x]) % MOD;
      }
      if (total_blocks - x <= g) {
        dp[curr][x] = (dp[curr][x] + dp[prev][x]) % MOD;
      }
    }
  }
  int ans = 0;
  int final_row = h & 1;
  for (int x = 0; x <= r; x++) {
    ans = (ans + dp[final_row][x]) % MOD;
  }

  cout << ans << "\n";
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
