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
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x)) //lower_boundの場所
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x)) //upper_boundの場所
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

const ll MOD = LONG_MAX;
const ll INF = 1e9 + 5;
const double PI = 3.14159265358979323846;

typedef pair<int, int> P;

ll q, n;

int main()
{
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> k(q);
  rep(i, n) cin >> a[i];
  rep(i, q) cin >> k[i];

  rep(i, q)
  {
    ll th = k[i];
    int preT = 0;
    while (true)
    {
      int t = Upper_bound(a, th);
      if (t == preT)
        break;
      th += t - preT;
      preT = t;
    }
    cout << th << endl;
  }
}
