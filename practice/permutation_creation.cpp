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
  vector<pair<ll, int>> neg_a;
  vector<pair<ll, int>> pos_a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= 0) {
      neg_a.push_back({x, i + 1});
    } else {
      pos_a.push_back({x, i + 1});
    }
  }
  sort(neg_a.begin(), neg_a.end());
  sort(pos_a.rbegin(), pos_a.rend());
  for (auto x : neg_a) {
    cout << x.second << " ";
  }
  for (auto x : pos_a) {
    cout << x.second << " ";
  }
  cout << nline;
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
