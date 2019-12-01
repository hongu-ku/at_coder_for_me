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

const ll N = 1e5+5;
vector<ll> v[N];
int n;
ll l[N],r[N];
set<ll> s;

int prime[N];      // i番目の素数
bool i_prime[N+1]; // 数字iが素数かどうか
int num_prime[N];  // 数字iまでの"2017に似た数""の個数
// n以下の素数の数を返す O(n log log n) ≒ O(n)
int sieve(int n) {
  int p = 0;
  rep(i,n+1) i_prime[i] = true;
  i_prime[0] = i_prime[1] = false;
  for(int i = 2; i<=n; i++) {
    num_prime[i] = num_prime[i-1];
    if(i_prime[i]) {
      if(i%2 && i_prime[(i+1)/2]) num_prime[i]++;
      prime[p++] = i;
      for(int j = 2*i; j<=n; j += i) i_prime[j] = false;
    }
  }
  return p;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> l[i] >> r[i];
  }
  sieve(N);
  rep(i,n) {
    cout << num_prime[r[i]] - num_prime[l[i] - 1] << endl;
  }
  // cout << << endl;
}
