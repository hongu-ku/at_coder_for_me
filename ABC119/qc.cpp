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

#define ll long long
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 99999
using namespace std;

ll ret0,ret1,ret2,ret3,A,B,C,N;
vector<ll> l;

ll dfs(ll cur, ll a, ll b, ll c) {
  // cout << cur << " : " << a << " : " << b << " : " << c << " : " <<
  // (min({a,b,c}) > 0 ? abs(a-A) + abs(b-B) + abs(c-C) - 30 : INF) << endl;
  if(cur == N) {
    if(min({a,b,c}) > 0) return abs(a-A) + abs(b-B) + abs(c-C) - 30;
    else return INF;
  }
  ret0 = dfs(cur + 1, a, b, c);
  ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
  ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
  ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
  cout << cur  << " : " << a << " : " << b << " : " << c
  << " : " << ret0  << " : " << ret1  << " : " << ret2  << " : " << ret3 <<
   " : " << min({ret0,ret1,ret2,ret3}) << endl;
  return min({ret0,ret1,ret2,ret3});
}

int main() {
  cin >> N >> A >> B >> C;
  ll temp;
  for (ll i = 0; i < N; i++) {
    cin >> temp;
    l.push_back(temp);
  }
  // sort(l.begin(), l.end(), greater<int>());
  ll result = dfs(0,0,0,0);
  cout << result << endl;

}
