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

vector<string> grey(int n) {
  vector<string> ans;
  if (n == 1) {
    ans.pb("0");
    ans.pb("1");
  } else {
    vector<string> b = grey(n - 1);
    for (int i = 1; i <= (1 << (n - 1)); i++) {
      ans.pb(b[i - 1] + "0");
    }
    for (int i = (1 << (n - 1)); i >= 1; --i) {
      ans.pb(b[i - 1] + "1");
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<string> ans = grey(n);
  for (auto x : ans) {
    cout << x << "\n";
  }
}

int main() {
  fastio();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
