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
int n,k;

int main() {
  cin >> n >> k >> s;
  v.push_back(0);
  rep(i,n-1) {
    if(s[i] != s[i+1]) v.push_back(i+1);
  }
  v.push_back(n);
  if(2*k >= v.size()) {
    cout << n << endl;
    return 0;
  };
  ll result = 0;
  if(s[0] == '0') result = v[2*k];
  // cout << result << endl;
  if(s[n-1] == '0') result = max(result, v.back() - v[v.size() - 1 - 2 * k]);
  // cout << result << endl;
  for(int i=s[0] == '0' ? 1 : 0; i+2*k+1 < (s[n-1] == '0' ? v.size()-1 : v.size()); i+=2) {
    result = max(result, v[i+2*k+1] - v[i]);
    // cout << result << endl;
  }
  cout << result << endl;
}
