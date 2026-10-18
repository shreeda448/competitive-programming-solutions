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

// Vector IO
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

int precompute(vector<vector<pair<int, int>>> &adj, int parent, int cur,
               vector<int> &sub_sz) {
  int res = 1;
  for (auto x : adj[cur]) {
    if (x.first != parent) {
      res += precompute(adj, cur, x.first, sub_sz);
    }
  }
  sub_sz[cur] = res;
  return res;
}

void dfs(vector<vector<pair<int, int>>> &adj, int parent, int cur,
         vector<int> &sub_sz, long long &tot, vector<long long> &res) {
  int n = adj.size() - 1;
  for (auto x : adj[cur]) {
    if (x.first != parent) {
      int v = x.first;
      long long edge_idx = x.second;
      if (sub_sz[v] > n - sub_sz[v]) {
        res[v] += edge_idx;
      } else {
        res[v] -= edge_idx;
        tot += edge_idx;
      }
      dfs(adj, cur, v, sub_sz, tot, res);
    }
  }
}

void spread(vector<vector<pair<int, int>>> &adj, int parent, int cur,
            vector<long long> &res) {
  for (auto x : adj[cur]) {
    if (x.first != parent) {
      res[x.first] += res[cur];
      spread(adj, cur, x.first, res);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i + 1});
    adj[v].push_back({u, i + 1});
  }
  ll tot = 0;
  vector<ll> res(n + 1);
  vector<int> sub_sz(n + 1);
  precompute(adj, 0, 1, sub_sz);
  dfs(adj, 0, 1, sub_sz, tot, res);
  int flow = 0;
  spread(adj, 0, 1, res);
  for (int i = 1; i <= n; i++) {
    res[i] += tot;
    cout << res[i] << " ";
  }
  cout << nline;
  return;
}

int main() {
  fastio();
  cout << fixed << setprecision(10);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
