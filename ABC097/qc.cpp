#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  string s;
  string temp;
  vector<vector<int> > index('z' - 'a' + 1);
  vector<string> koho;
  int k;
  cin >> s;
  cin >> k;
  for (size_t i = 0; i < s.length(); i++) {
    index[s[i] - 'a'].push_back(i);
  }
  for (size_t i = 0; i < 'z' - 'a' + 1; i++) {
    if (!index[i].empty()) {
      for (size_t p = 0; p < index[i].size(); p++) {
        for (size_t j = 0; j < 5; j++) {
          temp.clear();
          for (size_t k = 0; k <= j; k++) {
            if (index[i][p] + k == s.length()) {
              break;
            }
            temp.push_back(s[index[i][p] + k]);
          }
          koho.push_back(temp);
        }
      }
      sort(koho.begin(), koho.end());
      koho.erase(unique(koho.begin(), koho.end()), koho.end());
      if (koho.size() >= 5) {
        cout << koho[k-1] << endl;
        return 0;
      }
    }
  }
  cout << koho[k-1] << endl;
  return 0;
}
