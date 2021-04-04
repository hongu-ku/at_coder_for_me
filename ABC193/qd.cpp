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

struct mint
{
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b)
{
  a.n += b.n;
  if (a.n >= MOD)
    a.n -= MOD;
  return a;
}
mint operator-(mint a, mint b)
{
  a.n -= b.n;
  if (a.n < 0)
    a.n += MOD;
  return a;
}
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

typedef pair<int, int> P;

const ll N = 1e5 + 5;
ll k;
string s, t;
vector<ll> aoki(10, 0), takahashi(10, 0);

int ctoi(char c)
{
  return c - '0';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k >> s >> t;
  vector<ll> card(10, k);
  rep(i, 4)
  {
    takahashi[ctoi(s[i])]++;
    aoki[ctoi(t[i])]++;
    card[ctoi(s[i])]--;
    card[ctoi(t[i])]--;
  }
  // cout << card[1] << endl;
  ll result = 0;
  FOR(i, 1, 10)
  {
    FOR(j, 1, 10)
    {
      takahashi[i]++;
      aoki[j]++;
      ll count = i == j ? card[i] * (card[i] - 1) : card[i] * card[j];
      // cout << i << " : " << j << " = " << count << endl;
      // 点数計算
      ll point_t = 0, point_a = 0;
      FOR(k, 1, 10)
      {
        point_t += k * pow(10, takahashi[k]);
        point_a += k * pow(10, aoki[k]);
      }
      result += point_t > point_a ? count : 0;
      takahashi[i]--;
      aoki[j]--;
    }
  }
  // cout << result << endl;
  pd((double)result / (double)(9 * (k - 1) * (9 * k - 8)));
  br();
}
