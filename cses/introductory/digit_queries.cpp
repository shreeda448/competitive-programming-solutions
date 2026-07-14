#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair

void solve() {
  long long k;
  cin >> k;
  long long cnt = 9;
  long long skipped = 0;
  for (long long len = 1; true; len++) {
    if (k > len * cnt) {
      k -= len * cnt;
      skipped += cnt;
    } else {
      long long skip = (k - 1) / len;
      skipped += skip;
      k -= skip * len;
      long long x = skipped + 1;
      cout << to_string(x)[k - 1] << "\n";
      return;
    }
    cnt *= 10;
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
