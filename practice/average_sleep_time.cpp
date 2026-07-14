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
  int n, k;
  cin >> n >> k;
  vector<double> a(n);
  for (auto &x : a)
    cin >> x;
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  double avg = sum;
  for (int i = 1; i < n - k + 1; i++) {
    sum += a[k - 1 + i] - a[i - 1];
    avg += sum;
  }
  avg /= (double)(n - k + 1);
  cout << fixed << setprecision(10) << avg << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
