#include <bits/stdc++.h>
#include <climits>
using namespace std;

int n;
int a[21];
long long ans = LLONG_MAX;

void f(int i, long long X, long long Y) {
  if (i == n) {
    ans = min(ans, abs(X - Y));
    return;
  }
  f(i + 1, X + a[i], Y);
  f(i + 1, X, Y + a[i]);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  f(0, 0, 0);
  cout << ans << "\n";
}
