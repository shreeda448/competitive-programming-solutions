#include <bits/stdc++.h>
#include <unistd.h>
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
  vector<pair<ll, ll>> segments(n);
  ll max_coordinate = 0;
  for (auto &x : segments) {
    cin >> x.first;
    cin >> x.second;
    max_coordinate = max(max_coordinate, x.second);
  }
  ll low = 0, high = max_coordinate;
  ll ans = high;
  while (low <= high) {
    ll mid = (low + high) / 2;
    bool possible = true;
    ll cur_left_bound = 0;
    ll cur_right_bound = 0;
    for (int i = 0; i < n; i++) {
      ll cur_segment_left_bound = segments[i].first;
      ll cur_segment_right_bound = segments[i].second;
      if (cur_left_bound - mid > cur_segment_right_bound ||
          cur_right_bound + mid < cur_segment_left_bound) {
        possible = false;
        break;
      } else {
        cur_left_bound = max(cur_left_bound - mid, cur_segment_left_bound);
        cur_right_bound = min(cur_right_bound + mid, cur_segment_right_bound);
      }
    }
    if (possible) {
      ans = min(ans, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
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
