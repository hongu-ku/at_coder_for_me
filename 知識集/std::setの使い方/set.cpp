#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  s.insert(1);
  s.insert(2);

  // 要素検索
  set<int>::iterator ite;

  ite = s.find(1);
  if(ite == s.end()) puts("not found");
  else puts("found");

  s.erase(3); // 要素の削除

  // 検索の別の方法
  if(s.count(3) != 0) puts("found");
  else puts("not found");

  // 要素を全てループ
  for (ite = s.begin(); ite != s.end(); ++ite) {
    printf("%d\n", *ite);
  }
  return 0;
}
