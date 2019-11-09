// 回文の半径を求めるプログラム
// 偶数個の回文は文字の間に$などの記号を挟み込むことで実現できる

#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int i = 0, j = 0, R[n];
  while (i < n) {
    cout << "(i,j) = (" << i << " , " << j << ")" << endl;  
    while (i-j >= 0 && i+j < n && s[i-j] == s[i+j]) ++j;
    R[i] = j;
    int k = 1;
    while (i-k >= 0 && i+k < n && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
    i += k; j -= k;
  }
  for (size_t i = 0; i < n; i++) {
    cout << R[i];
  }
  cout << endl;
}
