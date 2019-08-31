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
  int n,k,a,num=0,x=0,chenge=-1;
  long long b;
  cin >> n >> k;
  bool check[n];
  vector<pair<int, long long> > vec(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vec[i].first = b;
    vec[i].second = a;
    check[i] = false;
  }
  VSORT(vec);
  for (int j = 0; j < n ; j++){
    for (int i = 0; i < k; i++) {
      num+=vec[i].first;
      if(!check[vec[i].second]){
        check[vec[i].second] = true;
        x++;
      } else {
        chenge = i;
      }
    }
    num += x*x;
    max = max > num ? max : num;
    num = 0;
    x = 0;
  }

  for (int i = 0; i < n; i++) {
    cout << vec[i].first << "  " << vec[i].second << endl;
  }



  // cout << num << endl;
}
