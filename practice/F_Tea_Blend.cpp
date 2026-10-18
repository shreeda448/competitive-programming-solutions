#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
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
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (int i = 0; i < sz(v); ++i)
        out << v[i] << (i == sz(v) - 1 ? "" : " ");
    return out;
}

const int MAXN = 1e6;

vector<int> spf(MAXN + 1);

vector<int> sieve_spf(int n)
{
    vector<int> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);

    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    return spf;
}

void precompute()
{
    spf = sieve_spf(MAXN + 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> pr(n);
    for (int i = 0; i < n; i++)
    {
        ll num = a[i];
        while (num > 1)
        {
            ll g = spf[num];
            int cnt = 0;
            while (num % g == 0)
            {

                num /= g;
                cnt++;
            }
            if (cnt & 1)
                pr[i].push_back(g);
        }
    }
    map<vector<ll>, ll> mp;
    set<ll> od;
    for (int i = 0; i < n; i++)
    {
        for (int j : pr[i])
        {
            if (od.find(j) == od.end())
            {
                od.insert(j);
            }
            else
            {
                od.erase(j);
            }
        }
        if (od.size() <= 7)
        {
            mp[vector<ll>(od.begin(), od.end())]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = mp.find(pr[i]);
        if (it != mp.end())
        {
            ans += it->second;
        }
    }
    cout << ans << nline;
    return;
}

int main()
{
    fastio();
    cout << fixed << setprecision(10);
    precompute();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}