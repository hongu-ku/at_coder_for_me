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
// int si() { int x; scanf("%d", &x); return x; }
// long long sl() { long long x; scanf("%lld", &x); return x; }
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

class Nums {
public:
  int a,b,c;

  Nums(int _a, int _b,int _c) {
    a= _a;
    b=_b;
    c=_c;
  }

  bool operator<(const Nums& other) const {
    return a < other.a;
  }
};

int main () {
  //優先度付きキュー＿priority queue
  ll x,y,z,k;
  cin >> x >> y >> z >> k;
  std::vector<ll> A(x),B(y),C(z);

  for (size_t i = 0; i < x; i++) cin >> A[i];
  for (size_t i = 0; i < y; i++) cin >> B[i];
  for (size_t i = 0; i < z; i++) cin >> C[i];

  VSORT(A);VSORT(B);VSORT(C);
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  reverse(C.begin(),C.end());

  priority_queue<pair<ll, Nums> > pq;
  pq.push(make_pair(A[0] + B[0] + C[0], Nums(0,0,0)));
  // prio に入れたか管理する
  set<ll> s;
  s.insert(0);

  vector<ll> ans;
  while(ans.size() < k) {
    auto v = pq.top(); pq.pop();
    ans.push_back(v.first);
    for (size_t i = 0; i < 3; i++) {
      int a = v.second.a ;
      int b = v.second.b ;
      int c = v.second.c ;
      if(i==0) a++;
      if(i==1) b++;
      if(i==2) c++;
      //hashを作る
      int hash = (a << 20) + (b << 10) + c;
      if(s.find(hash) == s.end()) {
        s.insert(hash);
        pq.push(make_pair(A[a] + B[b] + C[c] , Nums(a, b, c)));
      }
    }
  }
  for (size_t i = 0; i < k; i++) {
    cout << ans[i] << endl;
  }

}
