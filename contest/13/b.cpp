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

// small observations
//  for (a,b,c) to be a crimson triplet, a%b==0 and c%b==0

void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int b = 1; b <= n; b++) {
    long long multiples = n / b;
    ans += multiples * multiples;
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
