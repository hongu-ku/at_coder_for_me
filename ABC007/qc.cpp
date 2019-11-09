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

const int n_max = 55, m_max = 55;
typedef pair<int, int> P;

char maze[n_max][m_max];
int sx, sy, gx, gy, n, m;

int d[n_max][m_max];

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};


int bfs () {
  queue<P> que;
  rep(i,n) rep(j,m) d[i][j] = INF;
  que.push(P(sx,sy));
  d[sx][sy] = 0;

  while (que.size()) {
    P p = que.front(); que.pop();
    // cout << p.first << " : " << p.second << endl;
    // 取り出してきた状態がゴールなら探索を終了
    if(p.first == gx && p.second == gy) break;
    rep(i,4) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m && d[nx][ny] == INF && maze[nx][ny] != '#') {
        // cout << nx << " : " << ny << endl;
        que.push(P(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}
string s;

int main() {
  cin >> n >> m;
  cin >> sx >> sy;
  cin >> gx >> gy;
  sx--;sy--;gx--;gy--;
  rep(i,n) {
    cin >> s;
    rep(j,m) maze[i][j] = s[j];
  }
  // cout << maze[1][1] << endl;
  int ans = bfs();
  cout << ans << "\n";
}
