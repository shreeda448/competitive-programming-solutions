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
  vector<int> p(n);
  for (auto &x : p)
    cin >> x;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int num = abs(p[i] - p[i + 1]);
    if (p[i] % num == 0 && p[i + 1] % num == 0) {
      ans++;
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
