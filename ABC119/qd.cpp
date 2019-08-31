#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

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

int main () {
  int A = si();
  int B = si();
  int Q = si();
  std::vector<ll> s(A),t(B),x(Q),k(A+B+Q,1e10+1);
  std::vector<pair<ll, int> > v;
  for (int i = 0; i < A; i++) {
    cin >> s[i];
    v.push_back(make_pair(s[i],0));
  }
  for (int i = 0; i < B; i++) {
    cin >> t[i];
    v.push_back(make_pair(t[i],1));
  }
  for (int i = 0; i < Q; i++) {
    cin >> x[i];
    v.push_back(make_pair(x[i],2));
  }
  VSORT(v);
  for (int i = 0; i < A+B+Q; i++) {
    int code = v[i].second;
    ll dist = v[i].first;
    if(code != 2) {
      for (int j = i-1; j >= 0; j--) {
        if(v[j].second != code && v[j].second != 2) {
          k[i] = min(k[i],abs(dist - v[j].first));
          break;
        }
      }
      for (int j = i+1; j < A+B; j++) {
        if(v[j].second != code && v[j].second != 2) {
          k[i] = min(k[i],abs(dist - v[j].first));
          break;
        }
      }
    }
  }
  for (int i = 0; i < A+B+Q; i++) {
    int code = v[i].second;
    ll dist = v[i].first;
    if(code == 2) {
      for (int j = i-1; j >= 0; j--) {
        if(v[j].second != 2) {
          result.push_back(min(k[i],abs(dist - v[j].first));
          break;
        }
      }
      for (int j = i+1; j < A+B; j++) {
        if(v[j].second != code && v[j].second != 2) {
          k[i] = min(k[i],abs(dist - v[j].first));
          break;
        }
      }
    }
  }

  pi(); br();
}
