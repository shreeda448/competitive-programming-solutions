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
  int n;
  cin >> n;
  if (n == 2) {
    cout << "1 2 1 2 2 1 1 2\n";
    return;
  }
  int offsets[4] = {0, 0, 1, 3};
  vector<int> a(4 * n);
  for (int k = 0; k < 4; ++k) {
    for (int i = 0; i < n; ++i) {
      int local_idx = (i + offsets[k]) % n;
      int global_pos = k * n + local_idx;

      a[global_pos] = i + 1;
    }
  }
  for (int i = 0; i < 4 * n; i++) {
    cout << a[i] << " ";
  }
  cout << nline;
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
