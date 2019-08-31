#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  // int n,num=0;
  const long long p = 1;
  long long k,n,result=0,num=0;
  unsigned long long fx =0 ;
  cin >> n >> k;
  std::vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }

  // int count = log2(*max_element(a.begin(), a.end()))+1;
  // cout << count << endl;
  for (long long i = 0; i < 40; i++) {
    for (long long j = 0; j < n; j++) {
      if(a[j] & (p<<i)) {
        a1++;
      } else {
        a0++;
      }
    }


  }
  // cout << "result: " << result << endl;
  for (long long i = 0; i < n; i++) {
    fx += result ^ a[i];
  }
  cout << fx << endl;
}
