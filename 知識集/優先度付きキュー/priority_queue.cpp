#include <iostream>
#include <queue>

using namespace std;

int main()
{
  priority_queue<int> q;
  // 昇順に処理する
  std::priority_queue<
      int,              // 要素の型はint
      std::vector<int>, // 内部コンテナはstd::vector (デフォルトのまま)
      std::greater<int> // 昇順 (デフォルトはstd::less<T>)
      >
      que;

  auto cmp = [](pair<int, int> n1, pair<int, int> n2) { return n1.second > n2.second; }; // ラムダ関数で特殊な比較
  priority_queue<
      pair<int, string>,
      vector<pair<int, string>>,
      decltype(cmp)>
      que2(cmp);

  int v[] = {1, 3, 7, 5, 4};
  for (size_t i = 0; i < 5; i++)
  {
    q.push(v[i]);
  }
  int max = q.top(); // 一番大きい数の取得
  q.pop();           // 一番大きい数の削除
  cout << max << endl;
}
