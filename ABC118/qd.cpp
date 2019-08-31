#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

struct a {
  int first;
  string second;
  int kosu;

  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
   bool operator<( const a& right ) const {
       return first == right.first ? second > right.second : first < right.first;
   }
};

int kuri(vector<struct a>& v) {
  if(v.begin() == v.end()) {
    return 0;
  } else {
    int g = v[v.begin()].first;

    v.erase(v.begin());
    for (int i = g; i >= 0; i--) {
      kuri(nokori -1, n - )
    }
  }
}

int main() {
  int n,m;
  string s = "";
  cin >> n >> m;
  std::vector<int> A(m);
  std::vector<struct a> v(m);
  std::vector<int> result;
  for (size_t i = 0; i < m; i++) {
    cin >> A[i];
    if(A[i] == 1) {
      v[i].first = 2;
      v[i].second = "1";
    } else if(A[i] == 7) {
      v[i].first = 3;
      v[i].second = "7";
    }else if(A[i] == 4) {
      v[i].first = 4;
      v[i].second = "4";
    }else if(A[i] == 2) {
      v[i].first = 5;
      v[i].second = "2";
    }else if(A[i] == 3) {
      v[i].first = 5;
      v[i].second = "3";
    }else if(A[i] == 5) {
      v[i].first = 5;
      v[i].second = "5";
    }else if(A[i] == 6) {
      v[i].first = 6;
      v[i].second = "6";
    }else if(A[i] == 9) {
      v[i].first = 6;
      v[i].second = "9";
    }else if(A[i] == 8) {
      v[i].first = 7;
      v[i].second = "8";
    }
    v[i].kosu = 0;
  }
  VSORT(v);
  int count = n / v[0].first;
  for(int i = count; i>=0; i--) {
    for(int j=0; j<m; j++) {
      v[j].kosu=0;
    }
    while(true) {

    }
  }

  if(n % v[0].first == 0) {
    for (int i = 0; i < count; i++) {
      result.push_back(v[0].second);
    }
  }
  cout << v[0].second << v[1].second << endl;
}
