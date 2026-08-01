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
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int invert_one = 0, invert_zero = 0, same_one = 0, same_zero = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && b[i] == 0)
      invert_one++;
    else if (a[i] == 0 && b[i] == 1)
      invert_zero++;
    else if (a[i] == 1 && b[i] == 1)
      same_one++;
    else if (a[i] == 0 && b[i] == 0)
      same_zero++;
  }
  if (invert_one == 0 && invert_zero == 0) {
    cout << 0 << nline;
    return;
  }
  if (invert_one % 2 == 1) {
    cout << 1 << nline;
    return;
  }
  if (invert_one > 0) {
    cout << 2 << nline;
    return;
  }
  if (same_one == 0 || same_zero == 0) {
    cout << -1 << nline;
  } else {
    cout << 2 << nline;
  }
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
