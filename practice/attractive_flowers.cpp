#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Fast I/O
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define nline "\n"
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

// Typedefs
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// vector IO
template <typename T> istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (int i = 0; i < sz(v); ++i)
    out << v[i] << (i == sz(v) - 1 ? "" : " ");
  return out;
}
void solve() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << "Stable" << nline;
    cout << 0 << nline;
    return;
  }
  vector<pair<int, ll>> op;
  ll cnt = 1;
  ll t1 = b;
  while (t1 > 0) {
    cnt *= 10;
    t1 /= 10;
  }
  while (true) {
    if (a % 9 == b % 9 && b >= a) {
      break;
    }
    if (b > 1e18 - cnt) {
      cout << "Broken" << nline;
      return;
    }
    b += cnt;
    cnt *= 10;
    if (op.size() == 0) {
      op.push_back({2, 0});
    }
    op.back().second++;
  }
  bool ok = false;

  ll k = (b - a) / 9;
  if (k > 0) {
    op.push_back({1, k});
    ok = true;
  } else if (k == 0) {
    ok = true;
  }
  if (!ok) {
    cout << "Broken" << nline;
    return;
  }
  cout << "Stable" << nline;
  reverse(all(op));
  cout << op.size() << nline;
  for (int i = 0; i < op.size(); i++) {
    if (op[i].first == 1) {
      cout << "+ " << op[i].second << nline;
    } else {
      cout << "- " << op[i].second << nline;
    }
  }
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
