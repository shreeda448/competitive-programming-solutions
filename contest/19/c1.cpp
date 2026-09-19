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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int ones_in_a[2] = {0, 0};
  int ones_in_b[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      ones_in_a[i % 2]++;
    }
    if (b[i] == '1') {
      ones_in_b[i % 2]++;
    }
  }
  if (ones_in_a[0] == ones_in_b[0] && ones_in_a[1] == ones_in_b[1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
