#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define size_t unsigned long long
#define ll long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repr(i, a) for (int i = (int)(a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
int si()
{
  int x;
  scanf("%d", &x);
  return x;
}
long long sl()
{
  long long x;
  scanf("%lld", &x);
  return x;
}
string ss()
{
  string x;
  cin >> x;
  return x;
}
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 5;

struct Node
{
  int depth;
  vector<int> children;
  vector<int> parents;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  vector<vector<int>> edge(n);
  rep(i, n - 1)
  {
    cin >> p[i + 1];
    p[i + 1]--;
    edge[p[i + 1]].push_back(i + 1);
  }
  int q;
  cin >> q;
  vector<int> u(q), d(q);
  rep(i, q)
  {
    cin >> u[i] >> d[i];
    u[i]--;
  }
  vector<Node> nodes(n);
  nodes[0] = {0, {}, {0}};
  unordered_map<int, int> m;
  rep(j, q)
  {
    m[u[j] * n + d[j]] = 0;
  }
  queue<int> que;
  que.push(0);

  while (!que.empty())
  {
    int parent = que.front();
    que.pop();
    for (int j : nodes[parent].parents)
    {
      if (m.count(j * n + nodes[parent].depth))
        m[j * n + nodes[parent].depth]++;
    }
    for (auto i : edge[parent])
    {
      que.push(i);
      vector<int> parents = nodes[parent].parents;
      parents.push_back(i);
      nodes[i] = {nodes[parent].depth + 1, {}, parents};
    }
  }

  rep(j, q)
  {
    cout << m[u[j] * n + d[j]] << endl;
  }
}
