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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  sort(a.begin(), a.end());

  int current_count = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      current_count++;
    } else {
      if (current_count % 2 == 0) {
        cout << "YES" << nline;
        return;
      }
      current_count = 1;
    }
  }
  if (current_count % 2 == 0) {
    cout << "YES" << nline;
    return;
  }

  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1] && a[i] - a[i - 1] <= k) {
      cout << "YES" << nline;
      return;
    }
  }

  cout << "NO" << nline;
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
