#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

// bool operator<(const S& left, const S& right) {
//         return left.value > right .value;
// }

int main () {
  priority_queue<int> pq;
  pq.push(1);
  pq.push(10);
  pq.push(5);
  auto v = pq.top(); pq.pop();
  cout << v << endl;
  auto w = pq.top(); pq.pop();
  cout << w << endl;
  auto z = pq.top(); pq.pop();
  cout << z << endl;
  // set<int> s;
  // s.insert(1);
  // s.insert(3);
  // s.insert(2);

  // if(s.find(1)) {
    // cout << s << endl;
  // }
  // std::vector<pair<int,int > > v;
  // pair<int, int> temp;
  // for (size_t i = 0; i < 3; i++) {
  //   temp.first=100+i;temp.second=i;
  //   v.push_back(temp);
  // }
  // sort(v.begin(),v.end());
  // cout << v[0].first << endl;
}
