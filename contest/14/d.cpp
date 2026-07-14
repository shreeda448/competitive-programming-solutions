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

int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve() {
  string a, b;
  cin >> a >> b;
  int nA = a.length();
  int nB = b.length();
  vector<int> prefix_mod_a(nA), prefix_mod_b(nB);
  prefix_mod_a[0] = num[a[0] - '0'] % 10;
  prefix_mod_b[0] = num[b[0] - '0'] % 10;
  for (int i = 1; i < nA; ++i) {
    prefix_mod_a[i] = (prefix_mod_a[i - 1] + a[i] - '0') % 10;
  }
  for (int i = 1; i < nB; ++i) {
    prefix_mod_b[i] = (prefix_mod_b[i - 1] + b[i] - '0') % 10;
  }
  if (prefix_mod_a.back() != prefix_mod_b.back()) {
    cout << -1 << nline;
    return;
  }
  int lenA = nA - 1;
  int lenB = nB - 1;
  vector<int> dp(lenB + 1, 0);
  for (int i = 0; i < lenA; ++i) {
    int prev = 0;
    for (int j = 0; j < lenB; ++j) {
      int temp = dp[j + 1];
      if (prefix_mod_a[i] == prefix_mod_b[j]) {
        dp[j + 1] = prev + 1;
      } else {
        dp[j + 1] = max(dp[j + 1], dp[j]);
      }
      prev = temp;
    }
  }
  cout << dp[lenB] + 1 << "\n";
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
