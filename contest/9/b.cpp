#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define nline "\n"

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> ones_count(k, 0);

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ones_count[i % k]++;
    }
  }

  for (int i = 0; i < k; i++) {
    if (ones_count[i] % 2 != 0) {
      cout << "NO" << nline;
      return;
    }
  }

  cout << "YES" << nline;
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
