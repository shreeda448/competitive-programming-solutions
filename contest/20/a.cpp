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

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k > (n / 2)) {
    cout << -1 << nline;
    return;
  }
  int minOps = 0;
  for (int i = 0; i < (k); i++) {
    if (s[i] != 'R') {
      minOps++;
      s[i] = 'R';
    }
  }
  for (int i = n - 1; i >= n - k; i--) {
    if (s[i] != 'L') {
      minOps++;
      s[i] = 'L';
    }
  }
  cout << minOps << nline;
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
