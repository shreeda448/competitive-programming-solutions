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
  vector<int> a(n);
  vector<int> b(n);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  int low =
      min(*min_element(a.begin(), a.end()), *min_element(b.begin(), b.end()));
  int high =
      max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
  int ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    int num_twos = 0;
    int num_zero_blocks = 0;
    bool in_zero_block = false;
    for (int i = 0; i < n; i++) {
      int c = (a[i] >= mid) + (b[i] >= mid);
      if (c == 2) {
        num_twos++;
        if (in_zero_block) {
          num_zero_blocks++;
          in_zero_block = false;
        }
      } else if (c == 0) {
        in_zero_block = true;
      }
    }
    if (in_zero_block) {
      num_zero_blocks++;
    }
    if (num_twos > num_zero_blocks) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
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
