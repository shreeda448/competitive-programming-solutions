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

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto &y : x)
    cin >> y;
  int q;
  cin >> q;
  vector<int> m(q);
  for (auto &y : m)
    cin >> y;
  sort(x.begin(), x.end());
  for (int i = 0; i < q; i++) {
    auto it = upper_bound(x.begin(), x.end(), m[i]);
    int idx = distance(x.begin(), it);
    cout << idx << "\n";
  }
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
