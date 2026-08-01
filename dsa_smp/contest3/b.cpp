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

int operations;
void dfs(int l, int r, vector<int> &p) {
  if (l == r)
    return;
  int mid = l + (r - l) / 2;
  dfs(l, mid, p);
  dfs(mid + 1, r, p);
  if (p[l] > p[mid + 1]) {
    for (int i = 0; i <= mid - l; ++i) {
      swap(p[l + i], p[mid + 1 + i]);
    }
    operations++;
  }
}

void solve() {
  int m;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }

  operations = 0;
  dfs(0, m - 1, p);

  bool is_sorted = true;
  for (int i = 0; i < m - 1; ++i) {
    if (p[i] > p[i + 1]) {
      is_sorted = false;
      break;
    }
  }

  if (is_sorted) {
    cout << operations << nline;
  } else {
    cout << -1 << nline;
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
