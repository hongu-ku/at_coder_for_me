/*
https://algo-logic.info/combination/
k <= 1e7, n < 1e9　で modが素数の時(巨大)
nが固定値でない場合は

前処理：O(k)
クエリ：O(k)
nが固定値の場合は

前処理：O(k)
クエリ：O(1)
*/
/* 前処理
 i が 0 から k のときまで、fact_inv[i], inv[i] を計算して結果を保存しておく(動的計画法)

*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// nが固定値でない場合
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
vector<long long> fact, fact_inv, inv;
void init_nCk(int SIZE)
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
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(k)
*/
long long nCk(int n, int k)
{
  assert(!(n < k));
  assert(!(n < 0 || k < 0));
  long long ans = 1;
  for (int i = n; i >= n - k + 1; i--)
  {
    ans *= i;
    ans %= MOD;
  }
  return ans * fact_inv[k] % MOD;
}

// nが固定値の場合

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