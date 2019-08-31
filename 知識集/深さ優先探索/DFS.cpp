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

using namespace std;
// 根付き木の深さ優先対策
// ABC138のc問題

const int maxi = 1e6+10;
vector<int> v[maxi]; //v[x].pb(y) で子供の情報を。v[y].pb(x)で親の情報を。
int n;
long long a[maxi];

void dfs(int x, int pred) {
  //ここに処理をかく
  cout << x << endl;

  for(int i:v[x]) {
    // cout << "i = " << i << endl;
    if(i != pred) dfs(i,x);
  }
}

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1,0);
}
