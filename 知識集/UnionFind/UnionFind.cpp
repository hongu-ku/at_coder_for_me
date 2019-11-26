#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

class UnionFind {
public:
  int par[N],size[N];
  void init (int n) { // init
    for (int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;
    }
  }

  int root(int x) { //find
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
    size[y] += size[x];
    par[x] = y;
  }

  int sizes(int x) {
    return size[x];
  }
};

int main () {
  int n; //最大要素
  cin >> n;
  // int par[n];
  UniteFind uf(n);
  uf.init();

}
