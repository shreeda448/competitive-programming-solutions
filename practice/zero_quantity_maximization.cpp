#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <numeric>
#include <utility>
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
  vector<ll> b(n);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  map<pair<ll, ll>, int> freq;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    ll x = a[i], y = b[i];
    if (x == 0 && y != 0) {
      continue;
    }
    if (x == 0 && y == 0) {
      cnt++;
      continue;
    }
    ll GCD = gcd(abs(x), abs(y));
    pair<ll, ll> p = {a[i] / GCD, b[i] / GCD};
    if (p.first < 0) {
      p.first = -p.first;
      p.second = -p.second;
    }
    freq[p]++;
  }
  int mx = 0;
  for (auto &[k, v] : freq) {
    mx = max(mx, v);
  }
  cout << mx + cnt << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
