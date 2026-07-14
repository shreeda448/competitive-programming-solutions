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
  vector<ll> a(n);
  ll positives = 0;
  for (auto &x : a) {
    cin >> x;
  };
  for (int i = n - 1; i > 0; --i) {
    if (a[i] >= 0) {
      a[i - 1] = a[i] + a[i - 1];
    }
  }
  for (auto u : a) {
    if (u > 0)
      positives++;
  }
  cout << positives << nline;
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
