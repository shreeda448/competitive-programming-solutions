#include <bits/stdc++.h>
#include <numeric>
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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  vector<ll> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = (prefix[i - 1] ^ a[i]);
  }
  bool possible = false;
  for (int i = 0; i < n; i++) {
    if (prefix[i] == (prefix[n - 1] ^ prefix[i])) {
      possible = true;
      break;
    }
  }
  int l = -1, r = -1;
  bool found_l = false;
  for (int i = 0; i < n; i++) {
    if (prefix[i] == prefix[n - 1] && !found_l) {
      l = i;
      found_l = true;
    }
    if (prefix[i] == 0) {
      r = i;
    }
  }
  if (!(l == -1 || r == -1 || l >= r)) {
    possible = true;
  }
  if (possible) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
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
