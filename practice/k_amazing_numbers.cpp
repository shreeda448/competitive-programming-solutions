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

const int MAX_N = 3e5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  vector<int> prev_idx(n + 1, -1);
  vector<pair<int, int>> max_dist(n + 1);
  for (int i = 1; i <= n; i++) {
    max_dist[i] = {-1, i};
  }
  vector<int> ans(n + 5, MAX_N + 3);
  for (int i = 0; i < n; i++) {
    int cur_num = a[i];
    max_dist[cur_num].first =
        max(max_dist[cur_num].first, i - prev_idx[cur_num] - 1);
    prev_idx[cur_num] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (max_dist[i].second != 0) {
      max_dist[i].first = max(max_dist[i].first, n - prev_idx[i] - 1);
    }
  }
  sort(max_dist.begin() + 1, max_dist.end());
  // for (auto x : max_dist) {
  //   cout << x.first << " " << x.second << nline;
  // }
  int mini = MAX_N + 10;
  ans[max_dist[1].first + 1] = max_dist[1].second;
  mini = max_dist[1].second;
  for (int i = 2; i <= n; i++) {
    ans[max_dist[i].first + 1] = min(mini, max_dist[i].second);
    mini = min(mini, max_dist[i].second);
  }
  for (int i = 2; i <= n; i++) {
    ans[i] = min(ans[i], ans[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == MAX_N + 3) {
      cout << -1 << " ";
      continue;
    }
    cout << ans[i] << " ";
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
