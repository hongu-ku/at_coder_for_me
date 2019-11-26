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

const int N = 1e5+5;


vector<int> v[N];
map<P, int> mp;
// unsigned short c[N][N];
// pair<int, P> p[N];

void dfs(int i, int color) {
  for(int j=0; j<v[i].size(); j++) {
    mp[P(i,v[i][j])] = j+1>=color ? j+2 : j+1;
    dfs(v[i][j], j+1>=color ? j+2 : j+1);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,a[N],b[N];
  cin >> n;
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    v[a[i]].push_back(b[i]);
  }
  dfs(1,N);
  int result = 0;
  rep(i,n-1) result = max(result, mp[P(a[i],b[i])]);
  cout << result << endl;
  rep(i,n-1) cout << mp[P(a[i],b[i])] << endl;
}
