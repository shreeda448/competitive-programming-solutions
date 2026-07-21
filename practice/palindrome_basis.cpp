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
const int MOD = 1e9 + 7;
const int MAXN = 4e4;
vector<int> palindromes;
vector<ll> dp(MAXN + 1);

int create_pal(int a, bool isOdd) {
  int n = a;
  int palin = a;
  if (isOdd)
    n /= 10;
  while (n > 0) {
    palin = palin * 10 + n % 10;
    n /= 10;
  }
  return palin;
}

void find_palindromes(vector<int> &pal, int n) {
  for (int i = 0; i < 2; i++) {
    int j = 1;
    while (true) {
      int palin = create_pal(j, i % 2);
      if (palin > n) {
        break;
      }
      pal.push_back(palin);
      j++;
    }
  }
}

void precompute() {
  find_palindromes(palindromes, MAXN);
  dp[0] = 1;

  for (int pal : palindromes) {
    if (pal > MAXN) {
      break;
    }
    for (int i = 0; i <= MAXN; i++) {
      if (i + pal <= MAXN)
        dp[i + pal] = (dp[i + pal] + dp[i]) % MOD;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  cout << dp[n] << nline;
}

int main() {
  fastio();
  precompute();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
