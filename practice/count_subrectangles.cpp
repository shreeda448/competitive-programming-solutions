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

vector<ll> rect_counter(vector<int> a) {
  int n = a.size();
  vector<ll> res(n + 1);
  int i = 0;
  while (i < n) {
    if (a[i] == 0) {
      i++;
      continue;
    }

    int j = i;
    while (j < n && a[j] == 1) {
      j++;
    }
    for (int len = 1; len <= j - i; len++) {
      res[len] += j - i - len + 1;
    }
    i = j;
  }

  return res;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  ll ans = 0;
  auto group_a = rect_counter(a);
  auto group_b = rect_counter(b);
  for (int i = 1; i < group_a.size(); i++) {
    if (k % i == 0 && k / i <= m) {
      ans += group_a[i] * group_b[k / i];
    }
  }
  cout << ans << "\n";
  return;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
