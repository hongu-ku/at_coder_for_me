#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define VSORT(v) sort(v.begin(), v.end());
using namespace std;

int main() {
  int n,m,temp;
  int num=0;
  cin >> n >> m;
  vector<int> p(n);
  vector<pair<int, int> > z(m);
  vector<vector<int> > v;
  vector<int> vec, allVec;
  for (size_t i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (size_t i = 0; i < m; i++) {
    cin >> z[i].first >> z[i].second;
    allVec.push_back(z[i].first);
    allVec.push_back(z[i].second);
    VSORT(allVec);
  }
  sort(z.begin(), z.end());
  while(z.size() != 0) {
    vec.erase(vec.begin(), vec.end());
    vec.push_back(z[0].first);
    vec.push_back(z[0].second);
    temp = 0;
    z.erase(z.begin());
    while (vec.size() != temp) {
      temp = vec.size();
      for (size_t i = 0; i < z.size();) {
        for (size_t j = 0; j < vec.size(); j++) {
          if(z[i].first == vec[j]) {
            vec.push_back(z[i].second);
            z.erase(z.begin() + i);
            i--;
            break;
          } else if (z[i].second == vec[j]) {
            vec.push_back(z[i].first);
            z.erase(z.begin() + i);
            i--;
            break;
          }
        }
        i++;
      }
    }
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (size_t i = 0; i < vec.size(); i++) {
      // cout << i << " : " << vec[i] << endl;
      for (size_t j = 0; j < vec.size(); j++) {
        if (p[vec[i] - 1] == vec[j]) {
          num++;
          break;
        }
      }
      // cout << num << endl;
    }
  }
  for (size_t i = 0; i < allVec.size() - 1; i++) {
    if (allVec[i+1] - allVec[i] > 1) {
      for (size_t j = 1; j < allVec[i+1] - allVec[i]; j++) {
        if (p[allVec[i] + j - 1] == allVec[i] + j) {
          num++;
        }
      }
    }
  }
  if (n - allVec.back() > 0)  {
    for (size_t j = 1; j < n - allVec.back() + 1; j++) {
      if (p[allVec.back() + j - 1] == allVec.back() + j) {
        num++;
      }
    }
  }
  cout << num << endl;
}
