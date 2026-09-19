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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (auto &x : a) {
    cin >> x;
    mx = max(mx, x);
  }
  ll ans = 0;
  ll low = 1, high = n;
  vector<bool> present(n, false);
  while (low <= high) {
    ll mid = (high - low) / 2 + low;
    for (int i = 0; i < n; i++) {
      present[i] = false;
    }
    vector<int> spares;
    for (int i = 0; i < n; i++) {
      if (a[i] < mid) {
        if (present[a[i]]) {
          spares.push_back(a[i]);
          continue;
        }
        present[a[i]] = true;
      } else {
        spares.push_back(a[i]);
      }
    }
    sort(spares.begin(), spares.end());
    int idx = 0;
    bool possible = true;
    for (int i = 0; i < mid; i++) {
      if (!present[i]) {
        while (idx < spares.size() && spares[idx] < 2 * i + 1) {
          idx++;
        }
        if (idx < spares.size()) {
          idx++;
        } else {
          possible = false;
          break;
        }
      }
    }
    if (possible) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << nline;
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
