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

const ll N = 1e4+5;
const ll MAX = 1e6+5;
string s;
ll n,k,result;
ll a[N];
map<ll,ll> num;

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
  cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n) {
      ll temp = a[i];
      for (int j = 2; j*j <= temp; j++) {
          ll nu = 0;
          while(temp % j == 0) {
              nu++;
              temp /= j;
          }
          num[j] = max(num[j], nu);
      }
      if(temp != 1) num[temp] = max(num[temp], 1LL);
  }
  rep(i,n) {
    ll temp = a[i];
    map<ll,ll> b;
    for (int j = 2; j*j <= temp; j++) {
        while(temp % j == 0) {
            b[j]++;
            temp /= j;
        }
    }
    if(temp != 1) b[temp] += 1;
    // for (auto ite = b.begin(); ite != b.end(); ++ite) {
    //     cout << i << " : " << ite->first << "  :  " << ite->second << endl;
    // }
    // 要素を全てループ
    ll yo = 1;
    for (auto ite = num.begin(); ite != num.end(); ++ite) {
        rep(j , ite->second - b[ite->first]) {
            yo = mul(yo, ite->first, MOD);
        }
    }
    // cout << i << " : " << yo << endl;
    result += yo;
    result %= MOD;
  }
  cout << result << endl;
  
}
