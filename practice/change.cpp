#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define nline '\n';
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  int one = 0, ten = 0, hun = 0;
  for (int i = 0; i < n; i++) {
    a[i] = (((a[i] / 1000) + 1) * 1000 - (a[i])) % 1000;
    one += (a[i] % 10);
    a[i] /= 10;
    ten += (a[i] % 10);
    a[i] /= 10;
    hun += (a[i] % 10);
  }
  cout << one << " " << ten << " " << hun << nline;
}
