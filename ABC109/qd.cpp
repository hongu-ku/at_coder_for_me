#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define VSORT(v) sort(v.begin(), v.end());
using namespace std;


int main() {
  int h,w,b;
  vector<int> v(1);
  cin >> h >> w;
  int a[h][w];
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++) {
       cin >> b;
       // if(b % 2) num++;
       a[i][j] = b;
    }
  }
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++) {
      if(i == h-1 && j == w-1) break;
      else if(j == w-1 && a[i][j] % 2) {
        a[i][j] -= 1;
        a[i+1][j] += 1;
        v.push_back(i);
        v.push_back(j);
        v.push_back(i+1);
        v.push_back(j);
      } else if(a[i][j] % 2) {
        a[i][j] -= 1;
        a[i][j+1] += 1;
        v.push_back(i);
        v.push_back(j);
        v.push_back(i);
        v.push_back(j+1);
      }
    }
  }
  v[0] = v.size()/4;
  cout << v[0] << endl;
  for (size_t i = 0; i < v[0]; i++) {
    cout << v[i*4 + 1] + 1 << ' ' << v[i*4 + 2] + 1 << ' ' << v[i*4 + 3] + 1 << ' ' << v[i*4 + 4] + 1 << endl;
  }
}
