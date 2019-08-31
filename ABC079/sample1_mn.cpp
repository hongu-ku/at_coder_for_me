#include <iostream>
#include <math.h>
#include <string>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

// n桁の数字のm桁連続で同じ数字が出てきた場合にyesを、出てこない場合にnoを表示するプログラム
int main () {
  string n;
  int M;
  int i = 0;
  int count = 0;
  cin >> n >> M;

  REP(i,n.length()) {
    if (n[i] == n[i+1]) {
      count++;
    } else {
      count = 0;
    }
    if (count == M - 1) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
