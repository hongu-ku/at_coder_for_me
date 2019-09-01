#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
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

const int MOD = 1e9 + 7;

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

const int maxi = 1e6+10;
string s;
// vector<int> v[maxi];
ll n,k;
ll a[maxi];

vector<vector<ll> > COMB(n + 1,vector<ll>(n + 1, 0));

void comb(int n, int r) {
  for (int i = 0; i < COMB.size(); i++) {
    COMB[i][0] = 1;
    [i][i] = 1;
  }
  for (int j = 1; j < COMB.size(); j++) {
    for (int k = 1; k < j; k++) {
      COMB[j][k] = (COMB[j - 1][k - 1] + COMB[j - 1][k]) % MOD; // MODで割った数。
    }
  }
}

long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
long long mul(long long a, long long b, long long m) { // これを使えー
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    long long res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
}
long long inv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a = mod(a - mul(t, b, m), m); swap(a, b);
        u = mod(u - mul(t, v, m), m); swap(u, v);
    }
    return mod(u, m);
}

int main () {
  cin >> n >> k;
  comb();
  for(int i = 1; i<=k; i++) {
    ll result = 0;
    result += COMB[k-1][i-1];
    result =  mul(result, COMB[n-k+1][i], MOD);
    cout << result << endl;
  }
}
