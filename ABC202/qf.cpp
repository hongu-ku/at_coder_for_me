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

typedef pair<ll, ll> P;

const ll N = 2e5+5;
string s;
vector<P> v;
ll n,d,a,X,H,result,num[N];
vector<ll> b,c;
queue<P> q;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> d >> a;
  rep(i,n) {
    cin >> X >> H;
    v.push_back(P(X,H));
  }
  VSORT(v);
  rep(i,n) {
    b.push_back(v[i].second);
    c.push_back(v[i].first);
  }
  ll num = 0;
  rep(i,n) {
    while(q.size() > 0 && q.front().first < v[i].first) {
      num -= q.front().second;
      q.pop();
    }
    v[i].second -= num * a;
    if (v[i].second > 0 ){
      ll temp = (v[i].second-1) / a + 1;
      q.push(P(v[i].first + 2 * d, temp));
      num += temp;
      result += temp;
    }
    //cout << i << " : " << num << endl;
  }
  cout << result << endl;
}
