#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdlib>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
using namespace std;


int main () {
  unsigned long long A, B, num=0;
  cin >> A >> B;
  std::vector<long long> vB(40),vA(40),v(40);
  // long long C = A - B + 1;
  vB[0] = B % 4 == 0 ||  B % 4 == 3 ? 0 : 1;
  for(long long i=1; i< 40; i++ ) {
    if (!(B >> i & 1)) vB[i] = 0;
    else {
      vB[i] = (B%(long long)pow(2,i+1) - (long long)pow(2,i) + 1)%2;
    }
  }
  if(A) {
    A--;
    vA[0] = A % 4 == 0 ||  A % 4 == 3 ? 0 : 1;
    v[0] = abs(vB[0] - vA[0]);
    for(long long i=1; i< 40; i++ ) {
      if (!(A >> i & 1)) vA[i] = 0;
      else {
        vA[i] = (A%(long long)pow(2,i+1) - (long long)pow(2,i) + 1) %2;
      }
      v[i] = abs(vB[i] - vA[i]);
    }
  } else {
    for(long long i=0; i< 40; i++ ) {
      v[i] = vB[i];
    }
  }
  for (long long i = 0; i < 40; i++) {
    num += v[i]%2 * (long long)pow(2,i);
  }
  // for(long long i = 0; i< 9; i++) {
  //   cout << vA[i] << " : " << vB[i] << endl;
  // }
  cout << num << endl;
}
