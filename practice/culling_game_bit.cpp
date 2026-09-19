#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define nline '\n'

struct Bit {
  int size;
  vector<ll> tr;
  Bit(int n) { // one indexed binary indexed tree
    tr = vector<ll>(n + 1);
    size = n;
  }
  void add(int k, ll x) {
    while (k <= size) {
      tr[k] += x;
      k += (k & -k);
    }
  }

  ll sum(int k) {
    ll res = 0;
    while (k > 0) {
      res += tr[k];
      k -= (k & -k);
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> p(n);
  for (auto &x : p) {
    cin >> x;
    x--;
  }
  set<int> imp;
  reverse(p.begin(), p.end());
  Bit b(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int cur = p[i];
    auto it = imp.upper_bound(cur);
    int prevImp;
    if (it == imp.begin() || b.sum(cur) - b.sum(*prev(it)) < a[cur]) {
      imp.insert(cur);
      prevImp = p[i];
    } else {
      prevImp = *(prev(it));
    }
    b.add(cur + 1, a[cur]);
    while (imp.upper_bound(cur) != imp.end()) {
      int idx = *imp.upper_bound(cur);
      if (b.sum(idx) - b.sum(prevImp) >= a[idx]) {
        imp.erase(idx);
      } else {
        break;
      }
    }
    ans[i] = imp.size() - 1;
  }
  reverse(ans.begin(), ans.end());
  for (auto nm : ans) {
    cout << nm << " ";
  }
  cout << nline;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
