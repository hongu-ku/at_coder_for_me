途中だ
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

class UnionFind {
  int par[N]; // 親
  int rank[N]; // 木の深さ
  int diff_weight[N];
  unsigned size_;
public:
  void init(int n, int sum = 0) {
    for (int i=0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = sum;
    }
  }
  unsigned size() {return size_;}
  // 木の根を求める
  int find(int x) {
    if(par[x] == x) {
     return x;
    } else {
      int r = find(par[x]);
      diff_weight[x] += diff_weight[par[x]]; // 累積和をとる
      return par[x] = r;
    }
  }
  int weight(int x) {
    find(x);
    return diff_weight[x];
  }
  // xとyの属する集合を併合
  void unite(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = find(x); y = find(y);
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
