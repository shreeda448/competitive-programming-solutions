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
  int k;
  cin >> k;
  vector<int> c(k);
  int cnt3 = 0, cnt2 = 0;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    if (c[i] >= 3) {
      cnt3++;
    }
    if (c[i] == 2) {
      cnt2++;
    }
  }
  if (cnt3 > 0) {
    cout << "YES" << nline;
    return;
  }
  if (cnt2 > 1) {
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
