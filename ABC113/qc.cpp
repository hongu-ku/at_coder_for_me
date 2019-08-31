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

struct prefecture {
  int p;
  long long y;
  int i;

  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
   bool operator<( const prefecture& right ) const {
       return p == right.p ? y < right.y : p < right.p;
   }
};

int main() {
  int n,m,x=1,temp = 0;
  cin >> n >> m;
  const int count = m;
  const long long con = 1000000000000, six = 1000000;
  vector<prefecture> v(m);
  std::vector<long long> vec(m);
  int p[m];
  long long y[m];
  for (int i = 0; i < m; i++) {
    cin >> p[i] >> y[i];
    v[i].p = p[i];
    v[i].y = y[i];
    v[i].i = i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < count; i++) {
    // cout << "v[" << v[i].i << "] = {" << v[i].p << " : " << v[i].y << "} " << endl;
  }
  for (int i = 0; i < m; i++) {
    if(temp == v[i].p){
      x++;
    } else {
      x = 1;
    }
    temp = v[i].p;
    // cout << six * v[i].p << endl;
    vec[v[i].i] = con + x + six * v[i].p;
    // vec[v[i].i] = v[i].y;
  }
  for (int i = 0; i < count; i++) {
    cout << to_string(vec[i]).substr(1) << endl;
    // cout << vec[i] << endl;
  }
  return 0;
}
