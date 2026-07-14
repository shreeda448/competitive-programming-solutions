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
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  ll counter = 0;
  ll min_moves = 0;
  while (l <= r) {
    if (l < r) {
      if (counter + a[l] < a[r]) {
        min_moves += a[l];
        counter += a[l];
        a[l] = 0;
        l++;
      } else {
        min_moves += (a[r] - counter);
        a[l] -= (a[r] - counter);
        counter = 0;
        min_moves++;
        r--;
        if (a[l] == 0)
          l++;
      }
    } else if (l == r) {
      if (counter > a[l]) {
        min_moves += a[l];
        l++;
        r--;
      } else if (counter == a[l]) {
        min_moves++;
        l++;
        r--;
      } else {
        if (a[l] == 1) {
          min_moves++;
          l++;
          r--;
          continue;
        }
        min_moves += ((a[l] - counter) / 2);
        ll rem = a[l] - ((a[l] - counter) / 2);
        counter += ((a[l] - counter) / 2);
        min_moves++;
        min_moves += rem - counter;
        l++;
        r--;
      }
    }
  }
  cout << min_moves << nline;
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
