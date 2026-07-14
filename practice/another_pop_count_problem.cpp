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
  int sum = 0;
  int pop_count = 0;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < k; j++) {
      if (sum + (1 << i) <= n) {
        sum += (1 << i);
        pop_count++;
      } else {
        cout << pop_count << nline;
        return;
      }
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
