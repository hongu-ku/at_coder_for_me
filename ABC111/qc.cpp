#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;


int main() {
  int n,m,max_odd=0,max_even=0,num_odd=1,num_even=1,second_odd=0,second_even=0,
  mn_odd,mn_even;
  cin >> n;
  m=n/2;
  std::vector<int> odd(m),even(m);
  for (int i = 0; i < m; i++) {
    cin >> odd[i] >> even[i];
  }
  VSORT(odd);
  VSORT(even);
  // cout << odd[0] << ':' << odd[1] << endl;
  for (int i = 1; i < m; i++) {
    if(odd[i] - odd[i-1]) {

      if(num_odd > max_odd) {
        second_odd = max_odd;
        max_odd = num_odd;
        mn_odd = odd[i-1];
      } else {
        second_odd = num_odd < second_odd ? second_odd : num_odd;
      }
      second_odd = 1 > second_odd ? 1 : second_odd;
      // cout << "debug1: " << second_odd << endl;
      num_odd = 1;
    } else if(i==m-1) {
      num_odd++;
      if(num_odd > max_odd) {
        second_odd = max_odd;
        max_odd = num_odd;
        mn_odd = odd[i-1];
      }else {
        second_odd = num_odd < second_odd ? second_odd : num_odd;
      }
      // cout << "debug2: " << max_odd << endl;
    } else {
      num_odd++;
    }
    if(even[i] - even[i-1]) {
      if(num_even > max_even) {
        second_even = max_even;
        max_even = num_even;
        mn_even = even[i-1];
      } else {
        second_even = num_even < second_even ? second_even : num_even;
      }
      second_even = 1 < second_even ? second_even : 1;
      num_even = 1;
    } else if(i==m-1) {
      num_even++;
      if(num_even > max_even) {
        second_even = max_even;
        max_even = num_even;
        mn_even = even[i-1];
      } else {
        second_even = num_even < second_even ? second_even : num_even;
      }
    } else {
      num_even++;
    }
  }
  // cout << "max_odd: " << max_odd << endl;
  // cout << "max_even: " << max_even << endl;
  // cout << "second_odd: " << second_odd << endl;
  // cout << "second_even: " << second_even << endl;
  int result = max_odd + max_even;
  if(mn_odd == mn_even) {
    result = max_even + second_odd >  max_odd + second_even ? max_even + second_odd : max_odd+second_even;
  }
  cout << n - result << endl;
}
