#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> q;
  // 昇順に処理する
  std::priority_queue<
    int,                // 要素の型はint
    std::vector<int>,   // 内部コンテナはstd::vector (デフォルトのまま)
    std::greater<int>   // 昇順 (デフォルトはstd::less<T>)
  > que;
  int v[] = {1,3,7,5,4};
  for (size_t i = 0; i < 5; i++) {
    q.push(v[i]);
  }
  int max = q.top(); // 一番大きい数の取得
  q.pop(); // 一番大きい数の削除
  cout << max << endl;
}
