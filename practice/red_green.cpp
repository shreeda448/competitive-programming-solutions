#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 15, mod = 1e9 + 7;
int r, g, h, ans, cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> r >> g;
  for (h = cnt[0] = 1; h * (h + 1) / 2 <= r + g; h++)
    for (int i = N - 1; i >= h; i--)
      (cnt[i] += cnt[i - h]) %= mod;
  h--;
  for (int i = 0; i <= r; i++)
    if (h * (h + 1) / 2 - i <= g)
      (ans += cnt[i]) %= mod;
  cout << ans << '\n';
}
