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
const double PI = 3.14159265358979323846;

struct Node
{
  ll val;
  Node *left;
  Node *right;
};

typedef pair<int, int> P;

const ll N = 20;
const ll M = 400;
int n;
unordered_map<int, bitset<10>> m;

void printResult(const bitset<10> &x, const bitset<10> &y)
{
  cout << "Yes\n"
       << x.count();
  rep(i, x.size())
  {
    if (x.test(i))
      cout << " " << i + 1;
  }
  cout << "\n"
       << y.count();
  rep(i, y.size())
  {
    if (y.test(i))
      cout << " " << i + 1;
  }
  cout << endl;
  return;
}

int main()
{
  cin >> n;
  vector<ll> a(n);
  int count = min(n, 9);
  rep(i, count)
  {
    cin >> a[i];
    a[i] %= 200;
    bitset<10> bs(0);
    bs.set(i);
    if (!m.emplace(a[i], bs).second)
    {
      printResult(m[a[i]], bs);
      return 0;
    }
  }
  for (int i = 0; i < (1 << count); i++)
  {
    bitset<10> bs(i);
    if (bs.count() < 2)
      continue;
    int sum = 0;
    rep(j, count)
    {
      if (bs.test(j))
      {
        sum += a[j];
      }
    }
    sum %= 200;
    if (!m.emplace(sum, bs).second)
    {
      printResult(m[sum], bs);
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
