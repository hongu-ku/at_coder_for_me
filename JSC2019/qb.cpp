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
#define rep(i,a) for(ll i=0;i<(a);i++)
#define REPR(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<long long>;
// using vvl = vector<vl>;
// using vs = vector<string>;
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

int kaijo (int a, int result) {
  if (a == 0) {
    return result;
  } else {
    return kaijo(a-1, result * a);
  }
}

int kaijo(int a) {
  return kaijo(a,1);
}

ll kaijo_ll (ll a, ll result) {
  if (a == 0) {
    return result;
  } else {
    return kaijo_ll(a-1, result * a);
  }
}

ll kaijo_ll(ll a) {
  return kaijo_ll(a,1);
}

long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
long long mul(long long a, long long b, long long m) {
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
  ll mod = 1e9+7;
  ll n,k,x, p, p1,u=0,u1=0;
  unsigned ll count=0;
  cin >> n >> k;
  std::vector<ll> a(n),c(n,0),m(n,0);
  rep(i,n){
    cin >> x;
    a[i] = x;
    rep(j,i) {
      if(x < a[j]) c[j]+=1;
      else if(x > a[j]) m[i]+=1;
    }
  }
  if(k%2) {
    p1 = mul(k,(k+1)/2, mod);
    p = mul((k-1)/2,k,mod);
  } else {
    p1 = mul(k/2,(k+1), mod);
    p = mul((k-1),k/2,mod);
  }
  // cout << p << " : " << p1 << endl;
  rep(i,n){
    u += m[i];
    u1 += c[i];
    // if(k > mod - k) k=k-mod;
    // u = (k-1) % mod;
    // u1 = k % mod;
    // u2 = (k+1) % mod;
    // p = u1 * u2 / 2 % mod;
    // p1 = u2 * u1 / 2 % mod;
    // cout << "m[" << i <<"] = " << m[i] << endl;
    // cout << "c[" << i <<"] = " << c[i] << endl;
    // cout << "u => " << u << ", u1 => " << u1 <<endl;

    // cout << count << endl;
  }
  count += mul(u,p,mod);
  count %= mod;
  // cout << count << endl;
  // cout << "c[" << i <<"] = " << c[i] << endl;
  count += mul(u1,p1,mod);
  count %= mod;

  cout << count << endl;
}
