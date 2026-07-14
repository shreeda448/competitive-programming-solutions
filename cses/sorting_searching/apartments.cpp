#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  vector<ll> b(m);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long answer = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    ll curA = a[i];
    ll curB = b[j];
    if (curB < curA - k) {
      j++;
    } else if (curB > curA - k) {
      if (curB <= curA + k) {
        answer++;
        i++;
        j++;
      } else {
        i++;
      }
    } else {
      answer++;
      i++;
      j++;
    }
  }
  cout << answer << nline;
}

int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
