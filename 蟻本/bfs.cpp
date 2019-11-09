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
const int MAX_M = 105, MAX_N = 105;

char maze[MAX_N][MAX_M + 1];
int n,m;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M]; // 各店までの最短距離の配列

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int bfs() {
  queue<P> que;
  // 全ての点をINFで初期化
  rep(i,n) rep(j,m) d[i][j] = INF;
  // スタート地点をキューに入れて、その点の距離を0にする
  que.push(P(sx,sy));
  d[sx][sy] = 0;

  // キューが空になるまでループ
  while (que.size()) {
    // キューの先頭を取り出す
    P p = que.front(); que.pop();
    // 取り出してきた状態がゴールなら探索を終了
    if(p.first == gx && p.second == gy) break;
    // 移動4方向をループ
    rep(i,4) {
      // 移動した後の点を(nx,ny)とする
      int nx = p.first + dx[i], ny = p.second + dy[i];

      // 移動が可能かの判定とすでに訪れたことがあるかの判定(d[nx][ny] != INFなら訪れたことがある)
      if(0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF) {
        // 移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
        que.push(P(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

string s;

int main () {
  cin >> n >> m;
  rep(i,n) {
    cin >> s;
    rep(j, m) maze[i][j] = s[j];
  }
  int res = bfs();
  printf("%d\n", res);
}
