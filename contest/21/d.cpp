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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1) {
      odd.push_back(a[i]);
    } else {
      even.push_back(a[i]);
    }
  }
  int even_min = 1e9;
  int even_max = -1e9;
  int odd_min = 1e9;
  int odd_max = -1e9;
  if (!even.empty()) {
    for (int i = 0; i < (int)even.size(); i++) {
      even_min = min(even_min, even[i]);
      even_max = max(even_max, even[i]);
    }
  }
  if (!odd.empty()) {
    for (int i = 0; i < (int)odd.size(); i++) {
      odd_min = min(odd_min, odd[i]);
      odd_max = max(odd_max, odd[i]);
    }
  }
  bool ok = true;
  if (even.size() > 1) {
    int mx = even[0];
    for (int i = 1; i < (int)even.size(); i++) {
      if (mx > even[i]) {
        if (odd_min > even[i] && odd_max < mx) {
          ok = false;
          break;
        }
      } else {
        mx = even[i];
      }
    }
  }
  if (odd.size() > 1) {
    int mx = odd[0];
    for (int i = 1; i < (int)odd.size(); i++) {
      if (mx > odd[i]) {
        if (even_min > odd[i] && even_max < mx) {
          ok = false;
          break;
        }
      } else {
        mx = odd[i];
      }
    }
  }
  if (ok) {
    cout << "YES" << nline;
    return;
  }
  cout << "NO" << nline;
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
