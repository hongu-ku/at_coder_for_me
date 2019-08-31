#include <iostream>
#include <string>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int h,w,count;
  string temp;
  cin >> h >> w;
  int s[h+2][w+2];
  count = h;
  for (size_t i = 0; i < h+2; i++) {
    for (size_t j = 0; j < w+2; j++) {
      s[i][j] = '.';
    }
  }
  for (size_t i = 0; i < h; i++) {
    cin >> temp;
    for (size_t j = 0; j < count; j++) {
      s[i+1][j+1] = temp[j];
    }
  }
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++) {
      if (s[i+1][j+1] == '#') {
        if (s[i][j+1] == '.' && s[i+1][j] == '.' && s[i+1][j+2] == '.' && s[i+2][j+1] == '.' ) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
