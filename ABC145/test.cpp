#pragma GCC optimize("Ofast")
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

#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)

using namespace std;
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void ps(const string &s) { printf("%s ", s.c_str()); }

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,k;
  cin >> n >> k;
  std::vector<ll> a(n),f(n);
  priority_queue<
    pair<ll, ll>,
    vector<pair<ll, ll> >  // 内部コンテナはstd::vector (デフォルトのまま)
  > que;
  rep(i,n) a[i] = sl();
  rep(i,n) f[i] = sl();
  VSORT(a);VSORT(f);
  rep(i,n) {
    que.push(make_pair(a[i]*f[n-i-1], a[i]));
  }
  rep(i,k) {
    pair<ll, ll> max = que.top();
    que.pop();
    if(max.first > 0) que.push(make_pair(max.first/max.second*(max.second - 1), max.second - 1));
    else que.push(max);
  }
  ll result = 0;
  rep(i,n) {
    result = max(result, que.top().first);
    que.pop();
  }
  cout << result << "\n";
}
