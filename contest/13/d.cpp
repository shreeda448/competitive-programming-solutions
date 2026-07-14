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
  int total_prime_factors = 0;
  int distinct_prime_factors = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      distinct_prime_factors++;
      while (n % i == 0) {
        total_prime_factors++;
        n /= i;
      }
    }
  }
  if (n > 1) {
    distinct_prime_factors++;
    total_prime_factors++;
  }
  int min_layers = total_prime_factors + distinct_prime_factors - 1;
  cout << min_layers << nline;
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
