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

const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> enemies(m);
  vector<int> nearestEnemy(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    };
    enemies[i] = {x, y};
    nearestEnemy[y] = max(nearestEnemy[y], x);
  }
  vector<int> maxLeft(n + 1);
  maxLeft[1] = 1;
  ll ans = 1;
  for (int i = 2; i <= n; i++) {
    maxLeft[i] = max(maxLeft[i - 1], nearestEnemy[i] + 1);
    ans += i - maxLeft[i] + 1;
  }
  cout << ans << nline;
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
