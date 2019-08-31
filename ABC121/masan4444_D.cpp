#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
// #include <bits/stdc++.h>
using namespace std;

#define size_t unsigned long long
typedef long long ll;
#define int unsigned long long
typedef vector<int> VI;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define debug(x) cerr << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
#define debug1(i, x) cerr << "(" << (i) <<  ") " << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
#define debug2(i, j, x) cerr << "(" << (i) << ", " << (j) <<  ") " << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
template <typename T> class vec2d : public vector<vector<T>> {
public:
    vec2d(int H, int W): vector<vector<T>> (H, vector<T>(W)) {
    }
};
template <typename T> istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) is >> x;
  //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいいです。
  return is;
}
template <typename T> ostream& operator << (ostream& os, vector<T>& vec){
  REP(i, vec.size()) {
    os << vec[i] << ( i+1 == vec.size() ? "" : " " );
  }
  return os;
}
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0);
        // cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

signed main(signed argc, char **argv) {
  int A, B;
  cin >> A >> B;
  int N;
  for (N = 0; ; N++) {
    if (B < pow(2, N)) {
      break;
    }
  }
  int M;
  for (M = 0; ; M++) {
    if (A < pow(2, M)) {
      break;
    }
  }
  debug(M);
  debug(N);
  vector<bool> v(N, 0);
  int ans = 0;
  if (A % 4 == 2 || A % 4 == 3) {
    ans ^= 1;
  }
  if (B % 4 == 1 || B % 4 == 2) {
    ans ^= 1;
  }
  // int ans = 0;
  int a,b;
  for (size_t i = 0; i < N - 1; i++) {
    int n = pow(2, i + 1);
    a = A % n;
    b = B % n;
    // debug(n);
    // debug(a);
    // debug(b);
    if (a >= n/2) {
      v[i] = v[i] ^ ((a - n/2)%2);
    }
    if (b >= n/2) {
      v[i] = v[i] ^ !((b - n/2)%2);
    }
  }
  // v[0] = (1 + B - A) % 2;
  if (M == N) {
    v[N - 1] = (1 + B - A) % 2;
  } else {
    v[N - 1] = (1 + B - (int)pow(2, N - 1)) % 2;
  }
  for (size_t i = 1; i < N; i++) {
    if (v[i] % 2 == 1) {
      ans += pow(2, i);
    }
  }
  // debug(v);
  // debug(ans);
  cout << ans << endl;
  return 0;
}
