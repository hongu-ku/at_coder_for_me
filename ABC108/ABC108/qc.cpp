#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int n,x,num=0;
  cin >> n >> x;
  int count = n/x;
  for (size_t i = 0; i < x; i++) {
    if(i*2 % x == 0) {
      num+= count*(count-1) + 1;
    }
  }
  // for (int i = n; i > 0; i--) {
  //   for (int j = i; j <= n; j++) {
  //     for (int k = j; k <= n; k++) {
  //       if ((i+j) % x == 0  && (k+j) % x == 0 && (i+k) % x == 0) {
  //         cout << "(" << i << "," << j << "," << k << ")" << endl;
  //         if(i-k == 0) num++;
  //         else if (i-j == 0 || j-k == 0) num += 3;
  //         else num += 6;
  //       }
  //     }
  //   }
  // }
  cout << num << endl;
}
