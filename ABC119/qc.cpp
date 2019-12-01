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
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 5;

int A,B,C,N;
vector<ll> l;

int dfs(int cur, int a, int b, int c) {
  int ret0,ret1,ret2,ret3;
  if(cur == N) {
    if(min({a,b,c}) > 0) return abs(a-A) + abs(b-B) + abs(c-C) - 30;
    else return INF;
  }
  ret0 = dfs(cur + 1, a, b, c);
  ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
  ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
  ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
  int d = min({ret0,ret1,ret2,ret3});
  // cout << cur  << " : " << a << " : " << b << " : " << c << " | " << ret0  << " : " << ret1  << " : " << ret2  << " : " << ret3 << " : " << min({ret0,ret1,ret2,ret3}) << " : d = " << d << endl;

  return d;
}

int main() {
  cin >> N >> A >> B >> C;
  int temp;
  for (ll i = 0; i < N; i++) {
    cin >> temp;
    l.push_back(temp);
  }
  // sort(l.begin(), l.end(), greater<int>());
  int result = dfs(0,0,0,0);
  cout << result << endl;

}
