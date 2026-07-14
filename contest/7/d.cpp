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
  int n, k;
  cin >> n >> k;
  string s, z;
  cin >> s >> z;
  ll bitsS = 0, bitsZ = 0, bitsB = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      bitsS++;
    if (z[i] == '1')
      bitsZ++;
    if (s[i] != z[i])
      bitsB++;
  }
  long long cntS, cntZ, cntB;
  long long N = (1LL << k);

  if (k % 2 != 0) {
    cntS = (N + 1) / 3;
    cntZ = cntS;
    cntB = cntS;
  } else {
    cntB = (N - 1) / 3;
    cntS = cntB + 1;
    cntZ = cntB + 1;
  }

  long long valS = bitsS * (n - bitsS);
  long long valZ = bitsZ * (n - bitsZ);
  long long valB = bitsB * (n - bitsB);

  long long total = cntS * valS + cntZ * valZ + cntB * valB;

  cout << total << "\n";
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
