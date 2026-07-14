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
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  bool needs_reorder = false;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      needs_reorder = true;
      break;
    }
  }
  vector<int> tempA = a;
  vector<int> tempB = b;
  sort(tempA.begin(), tempA.end());
  sort(tempB.begin(), tempB.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (tempA[i] < tempB[i]) {
      cout << -1 << nline;
      return;
    } else {
      ans += (tempA[i] - tempB[i]);
    }
  }
  if (needs_reorder) {
    ans += c;
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
