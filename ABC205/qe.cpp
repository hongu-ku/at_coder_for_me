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
const ll MAX = 2e6 + 100;

// nが固定値でない場合
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMBinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long nCk(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  COMBinit();

  ll out = nCk(n + m - (k + 1), n - (k + 1));
  for (int i = 1; k + 2 * i + 1 <= n + m; i++)
  {
    int l = k + 1 + 2 * i; // 左から個目までの間にk+i+1個のWが必要
    int r = k + 1 + i;
    if (r > n)
      break;
    out += (nCk(l - 2, i) - nCk(l - 4, i - 2)) * nCk(n + m - l, n - r);
  }
  if ((k + 1 - (n + m)) / 2)
  {
    int l = n + m;
    int r = k + m + 1;
    out += (nCk(l - 2, m) - nCk(l - 4, m - 2)) * nCk(n + m - l, n - r);
  }
  ll result = nCk(n + m, n) - out;
  result = result < 0 ? MOD + result : result;

  cout << result << endl;
}
