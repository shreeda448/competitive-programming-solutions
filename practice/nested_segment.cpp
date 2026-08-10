#include <algorithm>
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

bool cmp(const vector<ll> &a, const vector<ll> &b) {
  if (a[0] != b[0]) {
    return a[0] < b[0];
  }
  return a[1] > b[1];
}

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> seg(n, vector<ll>(3));
  int idx = 1;
  for (auto &x : seg) {
    cin >> x[0] >> x[1];
    x[2] = idx;
    idx++;
  }
  sort(seg.begin(), seg.end(), cmp);
  vector<pair<ll, ll>> suffix(n);
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      suffix[i] = {seg[i][1], seg[i][2]};
    } else {
      if (suffix[i + 1].first <= seg[i][1]) {
        suffix[i] = suffix[i + 1];
      } else {
        suffix[i] = {seg[i][1], seg[i][2]};
      }
    }
  }
  pair<int, int> p = {-1, -1};
  for (int i = 0; i < n - 1; i++) {
    if (suffix[i + 1].first <= seg[i][1]) {
      p = {seg[i][2], suffix[i + 1].second};
    }
  }
  cout << p.second << " " << p.first << nline;
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
