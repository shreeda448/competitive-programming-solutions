#include <bits/stdc++.h>
#include <climits>
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

// my solution
// do dfs
// if current node is leaf then add it to the leaf array
// if current node is not a leaf
//  1.for each of its children leaf nodes of each subtree
//      if min of current leaves is greater than max of next leaves then cnt++
//      if for this node cnt>1 then ans = NO else this node is valid

vector<int> dfs(int cur, int parent, vector<int> &a, vector<vector<int>> &adj) {
  vector<int> temp(3, 1);
  if (adj[cur].size() == 0) {
    return {a[cur - 1], a[cur - 1], 1};
  }
  if (adj[cur].size() == 1 && cur != 1) {
    temp = {a[cur - 1], a[cur - 1], 1};
  } else {
    temp[0] = INT_MAX;
    temp[1] = INT_MIN;
    vector<int> prev;
    bool first = true;
    int cnt = 0;
    vector<int> f;
    vector<int> l;
    for (int u : adj[cur]) {
      if (u != parent) {
        vector<int> t = dfs(u, cur, a, adj);
        l = t;
        if (t[2] == 0) {
          return {0, 0, 0};
        }
        if (first) {
          prev = t;
          f = t;
          first = false;
        } else {
          if (t[0] - prev[1] != 1)
            cnt++;
          prev = t;
        }
        temp[0] = min(temp[0], t[0]);
        temp[1] = max(temp[1], t[1]);
      }
    }
    if (f[0] - l[1] != 1)
      cnt++;

    if (cnt > 1) {
      temp[2] = 0;
    }
  }
  return temp;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u;
    cin >> u;
    adj[u].push_back(i + 2);
    adj[i + 2].push_back(u);
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> res = dfs(1, 0, a, adj);
  if (res[2] == 0) {
    cout << "NO" << nline;
    return;
  }
  cout << "YES" << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10); // Standardize floating point precision
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
