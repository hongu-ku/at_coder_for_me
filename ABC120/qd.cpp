#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

class UniteFind {
  long long par[100000],sizes[100000];
public:
  long long init (int n) { // init
    for (int i = 0; i < n; i++) {
      par[i] = i;
      sizes[i] = 1;
    }
  }

  long long root(int x) { //find
    if (par[x] == x) {
      return x;                      //根
    } else {
      return par[x] = root(par[x]);  //経路圧縮
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite (int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    sizes[x] += sizes[y];
    sizes[y] = -1;
    par[y] = x;
  }

  long long size(int x) {
    return sizes[root(x)];
  }
};

int main () {
  long long n,m,a,b;
  cin >> n >> m;
  std::vector<pair<long , long> > vec(m);
  unsigned long long ans[m+1];
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    vec[i].first = a;
    vec[i].second = b;
    ans[i] = 0;
  }
  ans[m] = n * (n-1) / 2;
  UniteFind uf;
  uf.init(n);
  for(int i = m-1; i >= 0; i--) {
    if(uf.same(vec[i].first -1, vec[i].second -1)){
      ans[i] = ans[i+1];
    } else {
      ans[i] = ans[i+1] - uf.size(vec[i].first-1) * uf.size(vec[i].second-1);
      uf.unite(vec[i].first-1, vec[i].second-1);
    }
  }
  for (int i = 1; i < m+1; i++) {
    cout << ans[i] << endl;
  }
}
