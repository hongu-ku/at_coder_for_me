#include <bits/stdc++.h>

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

typedef pair<int, int> P;

const int N = 1e6+5;
string s;
ll n,m;
ll a,b,x,pp,qq;
int p[8],q[8],c[8],d[8];
int kaijo(int a) {
  if(a == 0) return 1;
  return a * kaijo(a-1);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> p[i];
    rep(j,i) {
      if(p[j] < p[i]) c[i]++;
    }
    c[i] = p[i] - 1 - c[i];
    pp += pow(10,n-i-1) * p[i];
  }
  rep(i,n) {
    cin >> q[i];
    rep(j,i) {
      if(q[j] < q[i]) d[i]++;
    }
    d[i] = q[i] - 1 - d[i];
    qq += pow(10,n-i-1) * q[i];
  }  
  rep(i,n) {
    a += c[i] * kaijo(n-i-1);
    b += d[i] * kaijo(n-i-1);
  }
  cout << abs(a - b) << endl;
}
