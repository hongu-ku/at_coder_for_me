#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

class UnionFind {
  int par[N]; // 親
  int rank[N]; // 木の深さ

  void init(int n) {
    for (int i=0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }
  // 木の根を求める
  int find(int x) {
    if(par[x] == x) {
     return x;
    } else {
     return par[x] = find(par[x]);
    }
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  // xとyが同じ集合に属するかいなか
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >>;
  cout << << endl;
}
