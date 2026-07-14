#include <bits/stdc++.h>
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
  ll a, b, x;
  cin >> a >> b >> x;

  vector<ll> A;
  ll curr_a = a;
  while (true) {
    A.push_back(curr_a);
    if (curr_a == 0)
      break;
    curr_a /= x;
  }

  vector<ll> B;
  ll curr_b = b;
  while (true) {
    B.push_back(curr_b);
    if (curr_b == 0)
      break;
    curr_b /= x;
  }

  ll min_ops = -1;

  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {

      ll current_cost = i + j + abs(A[i] - B[j]);

      if (min_ops == -1 || current_cost < min_ops) {
        min_ops = current_cost;
      }
    }
  }

  cout << min_ops << nline;
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
