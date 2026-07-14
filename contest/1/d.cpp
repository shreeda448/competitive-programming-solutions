

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
  vector<pair<int, int>> coordinates(n);
  for (auto &x : coordinates) {
    cin >> x.first >> x.second;
  }
  sort(coordinates.begin(), coordinates.end());
  ll b = 0;
  for (int i = 0; i < n - 1; i++) {
    if (coordinates[i + 1].first - coordinates[i].first >= 1)
      b++;
  }
  sort(coordinates.begin(), coordinates.end(),
       [](const auto &a, const auto &b) { return a.second < b.second; });
  ll c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (coordinates[i + 1].second - coordinates[i].second >= 1)
      c++;
  }
  cout << b * c << nline;
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
