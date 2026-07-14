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
  string s;
  cin >> s;

  int val[2] = {1, 2};
  long long ans = 0;

  long long cnt[3] = {0};

  cnt[0] = 1;

  int curr_mod = 0;
  int alt_len = 1;

  for (int i = 0; i < n; i++) {
    curr_mod = (curr_mod + val[s[i] - '0']) % 3;
    ans += cnt[(curr_mod + 1) % 3] + cnt[(curr_mod + 2) % 3];
    cnt[curr_mod]++;
    if (i > 0 && s[i] != s[i - 1]) {
      alt_len++;
    } else {
      alt_len = 1;
    }
    ans -= (alt_len - 1) / 2;
  }

  cout << ans << "\n";
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
