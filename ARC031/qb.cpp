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

const int n_max = 1e5 + 5;

string s;
char a[10][10];
bool memo[10][10];


void dfs(int x, int y) {
  memo[x][y] = true;
  int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
  rep(i,4) {
    int nx = x+dx[i], ny = y+dy[i];
    if(0 <= nx && nx < 10 && 0 <= ny && ny < 10 && !memo[nx][ny] && a[nx][ny] == 'o') dfs(nx, ny);
  }
}

int main() {
  ios::sync_with_stdio(false);
  rep(i,10) {
    cin >> s;
    rep(j, 10) a[i][j] = s[j];
  }
  rep(k,10) rep(h,10) {
    int count = 0;
    if( a[k][h] == 'o') continue;
    a[k][h] = 'o';
    rep(i,10) rep(j,10) {
      if(a[i][j] == 'o' && !memo[i][j]) {
        // cout << "i : j = " << i << " : " << j << endl;
        dfs(i,j);
        count++;
      }
    }
    a[k][h] = 'x';
    rep(i,10) rep(j,10) memo[i][j] = false;
    if(count == 1) {
      // cout << "k : h = " << k << " : " << h << endl;
      cout << "YES" << endl;
      return 0;
    }
  }
  int count = 0;
  rep(i,10) rep(j,10) {
    if(a[i][j] == 'o' && !memo[i][j]) {
      // cout << "i : j = " << i << " : " << j << endl;
      dfs(i,j);
      count++;
    }
  }
  if(count == 1) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
