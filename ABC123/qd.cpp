#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define REP(i,a) for(int i=0;i<(a);i++)
#define REPR(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<long long>;
// using vvl = vector<vl>;
// using vs = vector<string>;
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

int dp[1000][1000][1000];

ll saiki(){

}


int main () {
  //優先度付きキュー＿priorrity queue
  unsigned ll x,y,z,k,a_num=0,b_num=0,c_num=0,min,min_num;
  cin >> x >> y >> z >> k;
  ll a[x+1],b[y+1],c[z+1];
  std::vector<pair<ll, int> > v;
  pair<ll, int> temp;
  for (size_t i = 0; i < x; i++) {
    a[i] = sl();
    temp.first=a[i];temp.second=1;
    v.push_back(temp);
  }
  for (size_t i = 0; i < y; i++) {
    b[i] = sl();
    temp.first=b[i];temp.second=2;
    v.push_back(temp);
  }
  for (size_t i = 0; i < z; i++) {
    c[i] = sl();
    temp.first=c[i];temp.second=3;
    v.push_back(temp);
  }
  a[x]=-100000000;b[y]=-100000000;c[z]=-100000000;
  sort(a,a+x,greater<ll>());sort(b,b+y,greater<ll>());sort(c,c+z,greater<ll>());
  VSORT(v);
  ll k=0,l=1,m=2,count=v.size()-1
  l.push_back(v[count-k]+v[count-l]+v[count-m])
  for (size_t i = count; i < 0; i--) {
    l.push_back(v[count-k]+)
  }
  // for (size_t i = 0; i < k;) {
  //   dp
  // }
  // sort(v.begin(),v.end(),greater<ll>());
  // dp[0][0][0]=a[0]+b[0]+c[0];
  // REP(j,x) REP(k,y) REP(l,z) {
  //   dp[j+1][k][l] = dp[j][k][l] - a[j+1] +a[j];
  //   dp[j][k+1][l] = dp[j][k][l] - b[k+1] +b[k];
  //   dp[j][k][l+1] = dp[j][k][l] - c[l+1] +c[l];
  // }



  // pi(); br();
}
