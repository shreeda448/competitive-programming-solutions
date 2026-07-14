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
const int MOD = 998244353;
// Binary exponentiation for O(log b) calculation
ll power(ll base, ll exp) {
  ll res = 1;
  base = base % MOD;

  while (exp > 0) {
    // If exp is odd, multiply base with result
    if (exp % 2 == 1) {
      res = (res * base) % MOD;
    }
    // Square the base and halve the exponent
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}
// for first r rows , possible ways = 2^(r*c-1)*2^(r-1)(m-c)*2^(c-1)(n-r)
// r*c-1 = 5+1 = 6
// n m r c
// Test case 1 :
// 1 1 1 1
// output = 1;
// ans = 1;
// test case 2 :
// 2 3 1 2
// test case 3 :
// 2 5 2 2
//
// output = 2^(2*2-1)
//
// 000
// 000
//
// 001
// 001
//
// 010
// 010
//
// 011
// 011
//
// 100
// 100
//
// 101
// 101
//
// 010
// 101
//
// 011
// 100
//
// 100
// 011
//
// 101
// 010
//
// 11
// 11
//
// 00
// 11
//
// 11
// 00

void solve() {
  ll n, m, r, c;
  cin >> n >> m >> r >> c;
  ll pow = (n * m) - ((n - r + 1) * (m - c + 1));
  cout << power(2, pow) << "\n";
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
