// 文字列が与えられた時、各 i について「S と S[i:|S|-1] の最長共通接頭辞の長さ」を記録した配列 A を O(|S|) で構築するアルゴリズムです。
// ABC141のE問題で使用できる？

#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int i = 1, j = 0, A[n];
  A[0] = n;
  while (i < n) {
    while (i+j < n && s[j] == s[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < n && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
  for (size_t i = 0; i < n; i++) {
    cout << A[i];
  }
  cout << endl;
}
