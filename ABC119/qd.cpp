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
const ll INF = 1e12 + 5;

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

struct Point {
  int index;
  char c;
  ll number;
};

// 小さい順番
bool comp(const Point& e1, const Point& e2) {
  return e1.number < e2.number;
}

const ll N = 1e5+5;
vector<ll> v[N];
ll n;
ll a,b,q;
ll s,t,x;
vector<Point > p;
ll dif[N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b >> q;
  rep(i,a) {
    cin >> s;
    p.push_back((Point) {i,0,s});
  }
  rep(i,b) {
    cin >> t;
    p.push_back((Point) {i,1,t});
  }
  rep(i,q) {
    cin >> x;
    p.push_back((Point) {i,2,x});
  }

  sort(p.begin(),p.end(),comp);

  for(int i=0; i<p.size(); i++) {
    if(p[i].c == 2) {
      ll t_dif_l = INF, x_dif_l = INF;
      ll t_dif_r = INF, x_dif_r = INF;
      bool t_flag = false, x_flag = false;
      for(int j = i-1; j>=0; j--) {
        if(!t_flag && p[j].c == 1) {
          t_dif_l = min(t_dif_l, abs(p[i].number - p[j].number));
          t_flag = true;
        } else if(!x_flag && p[j].c == 0) {
          x_dif_l = min(x_dif_l, abs(p[i].number - p[j].number));
          x_flag = true;
        }
        if(t_flag && x_flag) break;
      }


      t_flag = false, x_flag = false;
      for(int j = i+1; j<p.size(); j++) {
        if(!t_flag && p[j].c == 1) {
          t_dif_r = min(t_dif_r, abs(p[i].number - p[j].number));
          t_flag = true;
        } else if(!x_flag && p[j].c == 0) {
          x_dif_r = min(x_dif_r, abs(p[i].number - p[j].number));
          x_flag = true;
        }
        if(t_flag && x_flag) break;
      }
      dif[p[i].index] = min(max(t_dif_l , x_dif_l),max(t_dif_r, x_dif_r));
      // cout << p[i].number << " : " << t_dif_l << " : " << t_dif_r << " * " << x_dif_l << " : " << x_dif_r << endl;
      dif[p[i].index] = min({dif[p[i].index], 2*t_dif_l+x_dif_r, t_dif_l+x_dif_r*2, 2*t_dif_r+x_dif_l, t_dif_r+x_dif_l*2});
      if(dif[p[i].index] >= INF) dif[p[i].index] = max(min(x_dif_r,x_dif_l),min(t_dif_r,t_dif_l));
      // cout << p[i].index << " : " << dif[p[i].index] << endl;
    }
  }
  rep(i,q) cout << dif[i] << endl;
}
