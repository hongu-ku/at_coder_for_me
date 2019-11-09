// 深さ優先探索

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
#include <stack>

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

string s;
int h,w;
char c[505][505];
int gi,gj;
bool memo[505][505];

bool dfs(int i, int j) {
  // cout << "i : j = " << i << " : " << j << endl;
  memo[i][j] = true;
  if(!memo[i+1][j] && i+1 < h && c[i+1][j] != '#')  dfs(i+1,j);
  if(!memo[i][j+1] && j+1 < w && c[i][j+1] != '#')  dfs(i,j+1);
  if(!memo[i][j-1] && j-1 >= 0 && c[i][j-1] != '#')  dfs(i,j-1);
  if(!memo[i-1][j] && i-1 >= 0 && c[i-1][j] != '#')  dfs(i-1,j);
  return memo[gi][gj];
}

int main () {
  int si,sj;
  cin >> h >> w;
  rep(i,h) {
    cin >> s;
    rep(j,w) {
      c[i][j] = s[j];
      if(c[i][j] == 's') si = i, sj = j;
      if(c[i][j] == 'g') gi = i, gj = j;
      }
  }
  // cout << si << sj << endl;
  if(dfs(si, sj)) printf("Yes\n");
  else printf("No\n");
}
