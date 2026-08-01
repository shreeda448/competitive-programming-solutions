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
  if (k == n - 1) {
    cout << -1 << nline;
    return;
  }
  int zeroes = (n + 1) / 2;
  int ones = (n) / 2;
  int num_blocks = n - k;
  int blocks_zero, blocks_ones;
  if (num_blocks % 2 == 0) {
    blocks_zero = (num_blocks / 2);
    blocks_ones = (num_blocks / 2);
  } else {
    blocks_zero = (num_blocks + 1) / 2;
    blocks_ones = (num_blocks - 1) / 2;
  }
  string s = "";
  s.reserve(n);
  for (int i = 0; i < num_blocks; i++) {
    if (i % 2 == 0) {
      s += '0';
      if (i == 0) {
        s.append(zeroes - blocks_zero, '0');
      }
    } else {
      s += '1';
      if (i == 1) {
        s.append(ones - blocks_ones, '1');
      }
    }
  }
  cout << s << nline;
  return;
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
