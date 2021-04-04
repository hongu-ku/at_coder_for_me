#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); i++)

using namespace std;

int main()
{
  vector<vector<int>> v = {{10, 15}, {999, 999}};
  rep(i, 5)
  {
    v.push_back({5 - i, i + 1});
  }
  rep(i, v.size())
  {
    cout << v[i][0] << endl;
  }

  sort(v.begin(), v.end(), [](auto a, auto b) { return a[0] < b[0]; });
  rep(i, v.size())
  {
    cout << v[i][0] << endl;
  }
}