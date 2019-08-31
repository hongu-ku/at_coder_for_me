#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t long long
using namespace std;


int main() {
  long long N,max=25;
  cin >> N;
  char s[N];
  cin >> s;
  long long checked[26];
  for (size_t i = 0; i < 26; i++) {
    checked[i] = 0;
  }
  for (size_t i = 0; i < N; i++) {
    checked[s[i] - 'a']++;
  }
  // sort(checked,checked+26,std::greater<char>());
  unsigned long long result = 1;
  for (size_t i = 0; i < 26; i++) {
    // if(!checked[i]) {
    //   max = i;
    //   break;
    // }
    result *= checked[i] + 1;
    result %=  1000000007;
  }


  // for(long long S = 1; S < (1<<max); S++) {
  //     long long sum = 1;
  //     for(int i = 0; i < max; i++) {
  //         if(S >> i & 1) {
  //           sum *= checked[i];
  //           sum %= 1000000007;
  //         }
  //     }
      // if (sum) {
      //   cout << sum <<endl;
      // }
  //     result += sum % 1000000007;
  //     result %= 1000000007 ;
  // }
  // for (size_t i = 0; i < s[N-1] - 'a'; i++) {
  //   for (size_t j = 0; j < i; j++) {
  //     /* code */
  //   }
  //   num += checked[i];
  // }

  // for (size_t i = 0; i < 26; i++) {
  //   cout << i << " : " << checked[i] << endl;
  // }
  // cout << checked[0] << endl;

  cout << result-1 << endl;
}
