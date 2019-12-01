#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;

// 蟻本P111
// 素数かどうかの判定 O(ルートn)
template <typename T> bool is_prime(T n) {
  for (int i = 2; i*i <= n; i++) {
    if( n % i == 0) return false;
  }
  return n != 1;
}

// 約数の列挙 O(ルートn)
template <typename T> vector<T> divisor(T n) {
  vector<T> res;
  for (int i = 1; i * i <= n; i++) {
    if(n%i == 0) {
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

// 素因数分解O(ルートn)
template <typename T> map<T,T> prime_factor(int n) {
  map<T, T> res;
  for(int i = 2; i*i <= n; i++) {
    while(n%i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

const int N = 10e3+5;
int prime[N];
bool i_prime[N+1];
int num_prime[N];  // 数字iまでの素数の個数
// n以下の素数の数を返す O(n log log n) ≒ O(n)
int sieve(int n) {
  int p = 0;
  rep(i,n+1) i_prime[i] = true;
  i_prime[0] = i_prime[1] = false;
  for(int i = 2; i<=n; i++) {
    if(i_prime[i]) {
      num_prime[i]++;
      prime[p++] = i;
      for(int j = 2*i; j<=n; j += i) i_prime[j] = false;
    }
  }
  return p;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << c << endl;
}
