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

typedef pair<ll, ll> P;

const int N = 3e5+5;
string s;
vector<int> v[N];
int n, k;
ll a[N],m[N], l[N];
ll result;
priority_queue<ll, vector<ll>, less<ll> > q;
priority_queue<ll, vector<ll>, greater<ll> > que;

int main () {
  cin >> n;
  n*= 3;
  rep(i,n) {
    cin >> a[i];
    if(i < n/3) {
      que.push(a[i]);
      m[0] += a[i];
    } else if(i>=n/3*2) {
      q.push(a[i]);
      l[n/3] += a[i];
    }
  }
  rep(i,n/3) {
    que.push(a[i+n/3]);
    m[i+1] = m[i] + a[i+n/3] - que.top();
    que.pop();
  }
  rep(i,n/3) {
    q.push(a[n/3*2 - i - 1]);
    l[n/3 - i - 1] = l[n/3 - i] + a[n/3*2 - i -1] - q.top();
    q.pop();
  }
  result = m[0] - l[0];
  rep(i,n/3 ) result = max(result, m[i+1] - l[i+1]);
  cout << result << endl;
}
