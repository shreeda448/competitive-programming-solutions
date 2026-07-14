#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <type_traits>
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
  vector<ll> b(n);
  for (auto &x : b)
    cin >> x;
  vector<bool> used(n, false);
  ll minMoves = 0;
  for (int i = 0; i < n; i++) {
    int best_j = -1;
    for (int j = 0; j < n; j++) {
      if (!used[j] && a[j] <= b[i]) {
        best_j = j;
        break;
      }
    }
    if (best_j == -1) {
      cout << -1 << nline;
      return;
    }
    used[best_j] = true;
    ll swaps = 0;
    for (int j = 0; j < best_j; j++) {
      if (!used[j]) {
        swaps++;
      }
    }
    minMoves += swaps;
  }
  cout << minMoves << nline;
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
