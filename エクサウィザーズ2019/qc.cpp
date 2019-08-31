#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
using namespace std;

int main() {
  ll N,Q,result = 0;
  cin >> N >> Q;
  char s[N];
  cin >> s;
  std::vector<char> t(Q),d(Q);
  vector<ll> num(N+2,1);
  num[0]=0;num[N+1]=0;
  vector<vector<ll> > v(26);
  for (ll i = 0; i < N; i++) {
    v[s[i] - 'A'].push_back(i+1);
  }
  // cout << v[0].size() << endl;
  // std::vector<pair<char, char> > v(Q);

  for (ll i = 0; i < Q; i++) {
    cin >> t[i] >> d[i];
    // cout << "[" << num[1] << " : " << num[2] << " : " << num[3] << "]" << endl;
  }
  for (ll i = 0; i < Q; i++) {
    char moji = t[i]-'A';
    if(d[i] == 'R') {
      for(ll j=0; j < v[moji].size(); j++){
        num[v[moji][j]+1] += num[v[moji][j]];
        num[v[moji][j]] = 0;
      }
    } else {
      for(ll j=0; j < v[moji].size(); j++){
        num[v[moji][j]-1] += num[v[moji][j]];
        // cout << "きてるで\n";
        num[v[moji][j]] = 0;
      }
    }
  }
  result = N - num[0] - num[N+1];
  cout << result <<endl;
}
