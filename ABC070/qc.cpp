#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 5;

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

typedef pair<int, int> P;

const ll N = 1e6+5;
vector<ll> v;
ll n,b;

template <typename T> T gcd(T a, T b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

template <typename T> T lcm(T a, T b) {
  return a / gcd(a, b) * b ;
}

template <typename T> T L_C_M(const vector<T> &list)
{
    if (list.size() < 2) return list[0];

    T a = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        a = lcm(a, list[i]);
    }
    return a;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> b;
    v.push_back(b);
  }
  ll d = L_C_M(v);
  cout << d << endl;
}