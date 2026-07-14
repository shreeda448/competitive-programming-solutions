#include <bits/stdc++.h>
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
  vector<pair<int, int>> trans;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int curr = a;
    int dist = 0;
    while (curr > 2) {
      trans.pb({curr, dist});
      if (curr % 2 == 0) {
        curr /= 2;
      } else {
        curr++;
      }
      dist++;
    }
    if (curr == 1) {
      trans.pb({1, dist});
      trans.pb({2, dist + 1});
    } else if (curr == 2) {
      trans.pb({1, dist + 1});
      trans.pb({2, dist});
    }
  }
  sort(trans.begin(), trans.end());
  ll minOps = -1;
  int cnt = 0;
  ll curCost = 0;
  for (int i = 0; i < trans.size(); i++) {
    if (i == 0 || trans[i].first != trans[i - 1].first) {
      if (cnt == n) {
        if (minOps == -1 || curCost < minOps) {
          minOps = curCost;
        }
      }
      cnt = 1;
      curCost = trans[i].second;
    } else {
      cnt++;
      curCost += trans[i].second;
    }
  }
  if (cnt == n) {
    if (minOps == -1 || curCost < minOps) {
      minOps = curCost;
    }
  }

  cout << minOps << "\n";
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
