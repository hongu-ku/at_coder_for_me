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
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
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

const ll N = 1e5+5;
ll n,result, k, t;
vector<ll> a;

int main () {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cin >> n >> k;
  rep(i,n) {
    cin >> t;
    a.push_back(t);
  }
  int keta = 0;
  for(int i = 60; i>=0; i--) {
    if((k >> i) & 1) {
      keta = i;
      break;
    }
  }
  ll x = 0;
  // cout << "keta = " <<  keta << endl;

  for(int i = keta; i >= 0; i--) {
    bool flag = false;
    ll num = 0, num2 = 0;
    rep(j,n) {
      if((a[j] >> i) & 1) num++;
      else num2++;
    }
    if(!flag && (k >> i) & 1 && num >= num2) {
      flag = true;
    }
    if(!flag && !((k >> i) & 1)) result += pow(2,i) * num;
    else if(num < num2) result += pow(2,i) * num2;//x += (1 << i);
    else result += pow(2,i) * num;
    // cout << pow(2,i) << " : " << num << " : " << num2 << " : " << result << endl;
  }

  rep(i,n) {
    // result += x ^ a[i];
  }
  // cout << x << endl;
  // int aaa = 1 ^ 0,  bbb = 6 ^ 0;
  // cout << aaa << " : " << bbb << " : " << (3^0) << endl;
  cout << result << endl;
}
