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

// one way , n->n*2^(k),op=  k+(n*2^(k)-m)
// two way , n->n-p,n-p->(n-p)*((n-p)*2^(k)),ops = p+k+((n-p)*2^(k)-m)
void solve() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    cout << n - m << nline;
    return;
  }
  int minOps = 0;
  while (m > n) {
    if (m % 2 == 0) {
      m /= 2;
    } else {
      m++;
    }
    minOps++;
  }
  cout << n - m + minOps << nline;
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
