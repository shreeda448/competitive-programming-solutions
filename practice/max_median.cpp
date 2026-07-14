#include <bits/stdc++.h>
#include <climits>
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  int low = 1, high = n;
  int max_median = INT_MIN;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int val = (a[i] >= mid) ? 1 : -1;
      pref[i + 1] = pref[i] + val;
    }
    bool found = false;
    int min_pref = 0;
    for (int i = k; i <= n; i++) {
      min_pref = min(min_pref, pref[i - k]);
      if (pref[i] - min_pref > 0) {
        found = true;
        break;
      }
    }
    if (found) {
      max_median = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << max_median << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
