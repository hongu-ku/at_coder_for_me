#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

long long barger(int L) {
  long long num;
  if(L ==0) {
    return 1;
  }
  num = 2 * barger(L-1) + 3;
  return num;
}

long long bar(int L) {

}

int main() {
  int num=0;
  int n,x;
  long long num_b;
  cin >> n >> x;
  num_b = barger(n);
  long long a = num_b;
  for (int i = 0; i < n; i++) {
    a = a/2;
    if(a < x){
      x -= a;
    }

    }
  }
  long long a = pow(2,51);
  while (a /= 10 ) {
    num++;
  }
  cout << num << endl;
}
