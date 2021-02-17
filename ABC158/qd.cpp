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
// const ll INF = 1LL << 60;
const int INF = 1e9 + 5;
const ll N = 2e5 + 5;

typedef pair<int, int> P;

string s;
int q;
vector<int> t, f;
vector<char> c;

void solve()
{
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> q;
  t.resize(q);
  f.resize(q);
  c.resize(q);
  rep(i, q)
  {
    cin >> t[i];
    if (t[i] == 2)
    {
      cin >> f[i] >> c[i];
    }
  }
  bool flag = false; // trueの時反転
  rep(i, q)
  {
    if (t[i] == 1)
      flag = !flag;
    else if (t[i] == 2)
    {
      if ((f[i] - 1) ^ flag)
        s += c[i];
      else
        s.insert(s.begin(), c[i]);
    }
  }
  if (flag)
    reverse(ALL(s));
  cout << s << endl;
  return 0;
}
