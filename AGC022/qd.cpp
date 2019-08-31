#include <iostream>
#include <cmath>


#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

long long query(long long a, long long b);

int main() {
  int q;
  cin >> q;
  const int count = q;
  unsigned long long a,b,result[q];
  for (size_t i = 0; i < count; i++) {
    cin >> a >> b;
    result[i] = query(a,b);
  }
  for (size_t i = 0; i < count; i++) {
    cout << result[i] <<endl;
  }

}

long long query (long long a,long long b) {
  long long num = 0;
  long long x,y;
  x = sqrt(a*b-1);
  y= 2*x;
  if (a <= x) {
    y--;
  }
  if (b <= y) y--;
  // x = 1; y = a * b - 1;
  // while (x < y) {
  //   if (x == a) {
  //     x++;
  //   } else if (x*y < a*b && y != b) {
  //     x++;
  //     y = a*b / x;
  //     num++;
  //   } else if (x*y >= a*b) {
  //     y--;
  //   } else if (x*y < a*b && y == b) {
  //     y--;
  //   }
  // }
  // y = 1; x = a * b - 1;
  // while (y <= x) {
  //   if (y == b) {
  //     y++;
  //   } else if (x*y < a*b && x != a) {
  //     y++;
  //     x = a*b / y;
  //     num++;
  //   } else if (x*y >= a*b) {
  //     x--;
  //   } else if (x*y < a*b && x == a) {
  //     x--;
  //   }
  // }
  return y;
}
