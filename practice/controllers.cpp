#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  int q;
  cin >> n;
  string s;
  cin >> s;
  cin >> q;
  int plus = 0;
  for (char ch : s)
    if (ch == '+')
      plus++;

  for (int i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    if (2 * plus == n) {
      cout << "YES\n";
      continue;
    }
    long long val1 = abs((n - 2 * plus) * b);
    long long val2 = (n - 2 * plus) * b;
    long long diff1 = abs(a - b);
    long long diff2 = a - b;
    if (!diff1) {
      cout << "NO\n";
      continue;
    }
    if (val1 % diff1 != 0) {
      cout << "NO\n";
      continue;
    }
    long long val3 = (val2 / diff2);
    if (val3 < plus - n || val3 > plus) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    continue;
  }
  return 0;
}
