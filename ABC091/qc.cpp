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
  int N,k,l;
  std::vector<int> a,b,c,d,v;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> k >> l;
    a.push_back(k);
    b.push_back(l);
  }
  for (size_t i = 0; i < N; i++) {
    cin >> k >> l;
    c.push_back(k);
    d.push_back(l);
  }
  int num = 0;
  for (size_t i = 0; i < N; i++) {
    int g = 0;
    for (size_t j = 0; j < N; j++) {
      if(a[j] < c[i] && b[j] < d[i]) g++;
    }
    v.push_back(g);
  }
  cout << v[0] << ' ' << v[1] << ' ' << v[2] <<endl;
  sort(v.begin(),v.end());//1,2,3,4,5
  cout << v[0] << ' ' << v[1] << ' ' << v[2] <<endl;
  for (int i = 0; i < v[v.size()-1]; i++) {
    int g = 0;
    for (int l = 0; l < v.size(); l++) {
      if(i <= v[l]) g++;
    }
    if (g >= i) num = i;

  }
    // for (size_t j = 0; j < N; j++) {
    //   int g = 0;
    //   for (size_t k = N-j; k > 0; k++) {
    //     for (size_t ruby = 0; ruby < N; ruby++) {
    //       if(a[ruby] < b[k] && c[ruby] < d[k]) g++;
    //     }
    //   }
    //   if (num < g) num = g;
    // }
  //
  // for (size_t i = 0; i < N; i++) {
  //   int g = 0;
  //   for (size_t j = 0; j < N; j++) {
  //     if (blue[j] == 1 && a[i] < c[j] && b[i] < d[j]) {
  //       g++;
  //       blue[j] = 0;
  //       break;
  //     }
  //   }
  //   if (num < g) num = g;
  // }

  cout << num << endl;
}
