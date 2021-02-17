// https://img.atcoder.jp/abc156/editorial.pdf
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
const ll INF = 1LL << 60;

typedef pair<int, int> P;

const ll N = 1e5 + 5;
ll n, a, b, k = 2e5;

// べき乗 繰り返し二乗法
ll mod_pow(ll x, ll n)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

vector<long long> fact_inv, inv, Com;
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
void init_nCk(int n, int SIZE)
{
  fact_inv.resize(SIZE + 5);
  inv.resize(SIZE + 5);
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < SIZE + 5; i++)
  {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }
  Com.resize(SIZE + 5);
  Com[0] = 1;
  for (int i = 1; i < SIZE + 5; i++)
  {
    Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
  }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int k)
{
  assert(!(k < 0));
  return Com[k];
}

ll solve()
{
  init_nCk(n, k);
  return ((mod_pow(2, n) - 1 - nCk(a) + MOD) % MOD - nCk(b) + MOD) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a >> b;
  k = min(k, n);
  cout << solve() << endl;
}
