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
  vector<pair<int, int>> left(n);
  vector<pair<int, int>> right(n);
  for (int i = 0; i < n; i++) {
    cin >> left[i].first >> left[i].second >> right[i].first >> right[i].second;
  }
  for (int i = n; i >= 1; i--) {
    int cur = 0;
    bool possible = true;
    for (int j = 1; j <= i; j++) {
      bool found = false;
      while (cur < n) {
        bool valid_left = false;
        bool valid_right = false;
        if (j < left[cur].first || j > left[cur].second) {
          valid_left = true;
        }
        if (i - j + 1 < right[cur].first || i - j + 1 > right[cur].second) {
          valid_right = true;
        }
        if (valid_left && valid_right) {
          found = true;
          cur++;
          break;
        }
        cur++;
      }
      if (!found) {
        possible = false;
        break;
      }
    }
    if (possible) {
      cout << i << nline;
      return;
    }
  }
  cout << 0 << nline;
  return;
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
