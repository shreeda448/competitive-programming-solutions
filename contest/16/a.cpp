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
  int sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  if (abs(sum) % 4 != 0)
    cout << "NO\n";
  else
    cout << "YES\n";
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
