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
  for (auto &x : a)
    cin >> x;
  int max_el = 0;
  int second_max_el = 0;
  int freq_max_el = 0;
  ll sum_of_a = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > max_el) {
      second_max_el = max_el;
      max_el = a[i];
    } else if (a[i] > second_max_el) {
      second_max_el = a[i];
    }
    sum_of_a += a[i];
  }
  for (auto x : a) {
    if (x == max_el)
      freq_max_el++;
  }
  ll ans = 0;
  vector<int> nice_indices;
  for (int i = 0; i < n; i++) {
    int max_of_remaining = 0;
    if (freq_max_el > 1) {
      max_of_remaining = max_el;
    } else if (a[i] == max_el) {
      max_of_remaining = second_max_el;
    } else {
      max_of_remaining = max_el;
    }
    if (2 * max_of_remaining == sum_of_a - a[i]) {
      ans++;
      nice_indices.push_back(i + 1);
    }
  }
  cout << ans << nline;
  for (auto x : nice_indices)
    cout << x << " ";
  cout << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
