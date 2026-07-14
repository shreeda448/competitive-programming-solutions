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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  int min_penalty = 0;
  if (n == 1) {
    cout << 0 << nline;
    return;
  }
  vector<int> b;
  vector<int> c;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      b.push_back(a[i]);
    } else {
      if (c.empty()) {
        if (b.back() >= a[i]) {
          b.push_back(a[i]);
        } else {
          c.push_back(a[i]);
        }
      } else if (b.back() >= a[i] && c.back() < a[i]) {
        b.push_back(a[i]);
      } else if (b.back() < a[i] && c.back() >= a[i]) {
        c.push_back(a[i]);
      } else if (b.back() >= a[i] && c.back() >= a[i]) {
        if (b.back() >= c.back()) {
          c.push_back(a[i]);
        } else {
          b.push_back(a[i]);
        }
      } else if (b.back() < a[i] && c.back() < a[i]) {
        if (b.back() >= c.back()) {
          c.push_back(a[i]);
        } else {
          b.push_back(a[i]);
        }
      }
    }
  }
  // cout << min_penalty << nline;
  for (int i = 0; i < b.size() - 1; i++) {
    min_penalty += (b[i] < b[i + 1]);
  }
  // cout << min_penalty << nline;
  if (!c.empty()) {
    for (int i = 0; i < c.size() - 1; i++) {
      min_penalty += (c[i] < c[i + 1]);
    }
  }
  cout << min_penalty << nline;
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
