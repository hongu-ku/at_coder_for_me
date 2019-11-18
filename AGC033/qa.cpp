// 幅優先探索

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

typedef pair<int, int> P;
const int N = 1005;

int n,m;
string s;
char a[N][N];
bool memo[N][N];
int dis[N][N];

int bfs(int x, int y) {
  int nx = x, ny = y;
  queue<P> que;
  que.push(P(x,y));
  int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
  rep(j,N) {
    P temp = que.front();que.pop();
    rep(i,4) {
      nx = temp.first + dx[i], ny = temp.second + dy[i];
      if(dis[nx][ny]) return abs(nx-x) + abs(ny-y) + dis[nx][ny];
      if(a[nx][ny] == '#') return abs(nx-x) + abs(ny-y);
      if(0 <= nx && nx < n && 0<= ny && ny < m) que.push(P(nx,ny));
    }
  }
  return 0;
}


int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  rep(i,n) {
    cin >> s;
    rep(j,m) {
      a[i][j] = s[j];
    }
  }
  rep(i,n) rep(j,m) {
    if(a[i][j]=='.') dis[i][j] = bfs(i,j);
  }
  int result = 0;
  rep(i,n) {
    rep(j,m) {
      result = max(result, dis[i][j]);
      // cout << dis[i][j];
    }
    // cout << endl;
  }
  cout << result << endl;
}
