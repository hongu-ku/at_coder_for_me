#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999
#define size_t unsigned long long
#define ll long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define ALL(a) a.begin(), a.end()
using namespace std;

const int MOD = 1e9 + 7;

typedef pair<int, int> P;
typedef struct edge
{
  int to, cost;
} E;

const int N = 1e5 + 5;
int pre[N];
int d[N]; // 頂点sからの最短距離
int V;    // 頂点数

// 始点sから各頂点への最短距離を求める
void dijkstra(int s, const vector<vector<edge>> &g)
{
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P>> que; // firstは最短距離、secondは頂点の番号
  fill(d, d + V, INF);
  fill(pre, pre + V, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    rep(i, g[v].size())
    {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost)
      {
        d[e.to] = d[v] + e.cost;
        pre[e.to] = v;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

// 頂点tへの最短路
vector<int> get_path(int t)
{
  vector<int> path;
  for (; t != -1; t = pre[t])
    path.push_back(t); // tがsになるまでprv[t]を辿っていく
  //このままだとt->sになっているので逆順にする
  reverse(ALL(path));
  return path;
}

int n, m, a, b, c;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> V >> m;
  vector<vector<edge>> G(N);
  rep(i, m)
  {
    cin >> a >> b >> c;
    E t1 = {b, c};
    G[a].push_back(t1);
    t1 = {a, c};
    G[b].push_back(t1);
  }
  dijkstra(0, G);
  cout << d[6] << endl;
}
