#include <bits/stdc++.h>

#define rep(i,a) for(int i=0;i<(a);i++)
using namespace std;

int n,k,result;
set<int> s;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> k;
    if(s.find(k) == s.end()) {
      s.insert(k);
      result++;
    }
  }
  cout << result << endl;
}
