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

const int INF = 1e9 + 7;
void mini(int &a, int b) { a = min(a, b); }

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  // dp[i][j] = min number of moves to transform first i characters from s to
  // first j characters in t if i want to transform first i characters from s to
  // first j+1 characters in t
  //  i have to insert a character , so dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1)
  //  if i want to transform first i characters from s to first j characters in
  //  t i have to delete a character ,so dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
  //  if
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int me = dp[i][j];
      if (j != m)
        mini(dp[i][j + 1], me + 1);
      if (i != n && j != m)
        mini(dp[i + 1][j + 1], me + (s[i] != t[j]));
      if (i != n)
        mini(dp[i + 1][j], me + 1);
    }
  }
  cout << dp[n][m] << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
