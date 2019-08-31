#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define CON 1000000000000
#define SIX 1000000
using namespace std;

struct a {
  int p;
  int y;
  int i;

  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
   bool operator<( const a& right ) const {
       return p == right.p ? y < right.y : p < right.p;
   }
};

int main() {
  const long long con = 1000000000000, six = 1000000;
  vector<struct a> v(3);
  v[0].p = 1;
  v[0].y = 2;
  v[0].i = 0;
  v[1].p = 2;
  v[1].y = 1;
  v[1].i = 1;
  v[2].p = 2;
  v[2].y = 5;
  v[2].i = 2;

  VSORT(v);
  int count = 3;
  for (size_t i = 0; i < count; i++) {
    // cout << "v[" << v[i].i << "] = {" << v[i].p << " : " << v[i].y << "} " << endl;
  }
  int g = 12345;
  // cout << to_string(g).substr(3) << endl;
  unsigned long long  ppap = six*100000;
  cout << ppap << endl;
}
