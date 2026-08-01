#include <bits/stdc++.h>
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
  int n, q;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;
  vector<int> one_zero(n + 1, 0);
  vector<int> zero_one(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    one_zero[i + 1] = one_zero[i] + (s[i] == '1' && t[i] == '0' ? 1 : 0);
    zero_one[i + 1] = zero_one[i] + (s[i] == '0' && t[i] == '1' ? 1 : 0);
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    int p = one_zero[r] - one_zero[l - 1];
    int q = zero_one[r] - zero_one[l - 1];
    int L = r - l + 1;

    if (L - (p + q) >= abs(p - q)) {
      cout << "YES" << nline;
    } else {
      cout << "NO" << nline;
    }
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
