#include <bits/stdc++.h>

using namespace std;

// (int がキー、const char* が値)
map<int, const char*> m;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  m.insert(make_pair(1, "ONE"));
  m.insert(make_pair(10, "TEN"));
  m[100] = "HUNDRED";

  // 要素検索
  map<int, const char*>::iterator ite;

  ite = m.find(1);
  puts(ite->second);

  ite = m.find(2);
  if(ite == m.end()) puts("not found");
  else puts(ite->second);

  puts(m[10]);

  m.erase(10); // 要素の削除

  // 要素を全てループ
  for (ite = m.begin(); ite != m.end(); ++ite) {
    printf("%d: %s\n", ite->first, ite->second);
  }
  return 0;
}
