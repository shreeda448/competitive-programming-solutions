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
  int n;
  cin >> n;
  map<ll, int> frA;
  map<ll, int> frB;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    frA[x]++;
  }
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    frB[x]++;
  }
  int op = 0;
  for (int i = 0; frA.size() > 1 || frB.size() > 1; i++) {
    ll mnA = frA.begin()->first;
    ll mxA = prev(frA.end())->first;
    ll mnB = frB.begin()->first;
    ll mxB = prev(frB.end())->first;
    ll one, two, three, four;
    one = abs(mxA - mxB);
    two = abs(mxA - mnB);
    three = abs(mnA - mnB);
    four = abs(mnA - mxB);
    ll tot_mn = min({one, two, three, four});
    ll tot_mx = max({one, two, three, four});
    if (i % 2 == 0) {
      if (tot_mn == one) {
        frA[mxA]--;
        if (frA[mxA] == 0) {
          frA.erase(mxA);
          frA.erase(mxA);
        }
      } else if (tot_mn == two) {
        frA[mxA]--;
        if (frA[mxA] == 0) {
          frA.erase(mxA);
          frA.erase(mxA);
        }
      } else if (tot_mn == three) {
        frA[mnA]--;
        if (frA[mnA] == 0) {
          frA.erase(mnA);
          frA.erase(mnA);
        }
      } else {
        frA[mnA]--;
        if (frA[mnA] == 0) {
          frA.erase(mnA);
          frA.erase(mnA);
        }
      }
    } else {
      if (tot_mx == one) {
        frB[mxB]--;
        if (frB[mxB] == 0) {
          frA.erase(mxB);
          frA.erase(mxB);
        }
      } else if (tot_mx == two) {
        frB[mnB]--;
        if (frB[mnB] == 0) {
          frA.erase(mnB);
          frA.erase(mnB);
        }
      } else if (tot_mx == three) {
        frB[mnB]--;
        if (frB[mnB] == 0) {
          frB.erase(mnB);
          frB.erase(mnB);
        }
      } else {
        frB[mxB]--;
        if (frB[mxB] == 0) {
          frB.erase(mxB);
          frB.erase(mxB);
        }
      }
    }
  }
  cout << abs(frA.begin()->second - frB.begin()->second) << nline;
  return;
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
