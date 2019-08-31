#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define VSORT(v) sort(v.begin(), v.end());
#define a 'A'
#define b 'B'
#define c 'C'
#define h '?'
using namespace std;

int main() {
  string t;
  int num = 0, h_num = 0;
  cin >> t;
  for (size_t i = 0; i < t.length(); i++) {
    if(t[i] == num)
  }
  for (size_t i = 0; i < t.length() - 2; i++) {
    for (size_t j = i+1; j < t.length() - 1; j++) {
      for (size_t k = j+1; k < t.length(); k++) {
        if((t[i] == a || t[i] == h) && (t[j] == b || t[j] == h) && (t[k] == c || t[k] == h)) {
          num++;
          cout << num << ':' << i << ':' << j << ':' << k << endl;
        }
      }
    }
  }
  cout << num << endl;
}
