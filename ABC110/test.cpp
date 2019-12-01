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
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

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
string s;
ll n,m;
ll a[N];

// 素因数分解O(ルートn)
template <typename T> map<T,T> prime_factor(T n) {
  map<T, T> res;
  for(int i = 2; i*i <= n; i++) {
    while(n%i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

// テーブルを作る前処理
void COMBinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COMB(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// a*b/m
ll mul(ll a, ll b, ll m) {
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    ll res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  map<ll, ll> v = prime_factor(m);
  v[1] = 1;
  ll result = 1;
  COMBinit();
  cout << COMB(3,2) << endl;
  COMBinit();
  cout << COMB(4,3) << endl;
  cout << result << endl;
}
