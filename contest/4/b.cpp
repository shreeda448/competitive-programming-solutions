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

  long long current_sum = 0;
  long long min_height = 2e18;

  for (int i = 1; i <= n; ++i) {
    long long a;
    cin >> a;

    current_sum += a;

    long long max_h_for_prefix = current_sum / i;

    min_height = min(min_height, max_h_for_prefix);

    cout << min_height << (i == n ? "" : " ");
  }
  cout << "\n";
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
