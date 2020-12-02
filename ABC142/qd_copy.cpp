#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(ll i=0;i<(a);i++)
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

const int N = 1e5+5;
string s;
vector<ll> v;
ll a,b;
ll bg, sm;
int result;
int h;

// 素因数分解O(ルートn)
map<ll,ll> prime_factor(ll n, ll m) {
  map<ll,ll> res;
  // cout << n << " : " << m << endl;
  for(ll i = 2; i*i <= n || i*i <= n; i++) {
    // cout << i << endl;
    while(n%i == 0 && m%i == 0) {
      // cout << 'a' << endl;
      ++res[i];
      n /= i; m/= i;
    }
    while(n%i == 0) n /= i;
    while(m%i == 0) m /= i;
  }
  if(n%m == 0 && m!=1 && n!=1) {
    res[n]++;
    // cout << "n" << n << endl;
  }
  if(m%n == 0 && n!=1 && m!=1) {
    res[m]++;
    // cout << m << endl;
  }
  return res;
}

int main () {
  cin >> a >> b;
  map<ll,ll> res = a > b ? prime_factor(a,b) : prime_factor(b,a);
  ll count = 1;
  for (auto ite = res.begin(); ite != res.end(); ++ite) {
    // cout << ite->first << endl;
    
    count++;
  }
  cout << count << endl;
}