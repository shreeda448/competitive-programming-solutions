#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 20, mod = 1e9 + 7;
int n, cnt[N], res[N], pw[N], ans;

void pre() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * 2 % mod;
  }
}

int main() {
  pre();
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int y = 1; y * y <= x; y++) {
      if (x % y == 0) {
        cnt[y]++;

        if (y * y != x) {
          cnt[x / y]++;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (cnt[i]) {
      res[i] = cnt[i] * 1ll * pw[cnt[i] - 1] % mod;
    }
  }

  for (int i = N - 1; i > 1; i--) {
    for (int j = 2 * i; j < N; j += i) {
      res[i] = (res[i] - res[j] + mod) % mod;
    }

    ans = (ans + i * 1ll * res[i]) % mod;
  }

  cout << ans << '\n';
}
