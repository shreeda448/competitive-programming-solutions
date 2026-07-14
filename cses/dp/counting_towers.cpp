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
const int N = 1e6;
int dp[N + 2][2];

void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

void precompute() {
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 0; i < N; i++) {
    add_self(dp[i + 1][0], (2LL * dp[i][0]) % MOD);
    add_self(dp[i + 1][1], dp[i][0]);
    add_self(dp[i + 1][0], dp[i][1]);
    add_self(dp[i + 1][1], (4LL * dp[i][1]) % MOD);
  }
}

void solve() {
  int n;
  cin >> n;
  cout << (1LL * dp[n - 1][0] + dp[n - 1][1]) % MOD << nline;
}

int main() {
  fastio();
  precompute();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
