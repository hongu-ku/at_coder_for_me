#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define REP(i,a) for(int i=0;i<(a);i++)
#define REPR(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<long long>;
// using vvl = vector<vl>;
// using vs = vector<string>;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const int MOD = 1e9 + 7;

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int main () {
  int N = si();
  std::vector<ll> a(N);
  ll mini=1e9+7,result=-10;
  for (size_t i = 0; i < N; i++) {
    cin >> a[i];
  }
  VSORT(a);
  if(N==2) {
    result = a[1];
    cout << result << endl;
    return 0;
  }

  std::vector<ll> ret0;
	for(ll i=1 ; i*i<=a[0] ; ++i)
	{
		if(a[0]%i == 0)
		{
			ret0.push_back(i);
			if(i!=1 && i*i!=a[0])
			{
				ret0.push_back(a[0]/i);
			}
		}
	}
  ret0.push_back(a[0]);

  std::vector<ll> ret1;
	for(ll i=1 ; i*i<=a[1] ; ++i)
	{
		if(a[1]%i == 0)
		{
			ret1.push_back(i);
			if(i!=1 && i*i!=a[1])
			{
				ret1.push_back(a[1]/i);
			}
		}
	}
  ret1.push_back(a[1]);
  VSORT(ret0);VSORT(ret1);
  // cout << ret0.size()-1 << endl;
  for (int i = ret0.size()-1; i >= 0; i--) {
    // cout << i << endl;
    int count=0;
    for (size_t j = 1; j < N; j++) {
      if(a[j]%ret0[i]) {
        count++;
        if(count == 2) {
          break;
        }
      }
    }
    // cout << ret0[i] << " : " << count << endl;
    if(count!=2) {
      result = ret0[i];
      // cout << result << endl;
      break;
    }
  }

  for (int i = ret1.size()-1; i >= 0; i--) {
    int count = 0;
    // cout << "OK" << endl;
    for (size_t j = 2; j < N; j++) {
      if(a[j]%ret1[i]) {
        count = 1;
        break;
      }
    }
    if(count!=1) {
      result = max(result,ret1[i]);
      break;
    }
  }
  // for (size_t i = 0; i < ret1.size(); i++) {
  //   cout << ret1[i] << endl;
  // }
  // for (size_t i = 0; i < ret0.size(); i++) {
  //   cout << ret0[i] << endl;
  // }
  cout << result << endl;
}
