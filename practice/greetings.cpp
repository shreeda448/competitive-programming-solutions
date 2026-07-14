#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  vector<pair<int, int>> ranges(n);
  ordered_set<ll> st;
  for (auto &x : ranges) {
    cin >> x.first;
    cin >> x.second;
  }
  sort(ranges.begin(), ranges.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += i - st.order_of_key(ranges[i].second);
    st.insert(ranges[i].second);
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
