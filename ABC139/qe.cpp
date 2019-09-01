#include <vector>
#include <iostream>

#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
using namespace std;

int main () {
  int n,k;
  scanf("%d",&n);
  int a[n][n];
  std::vector<int> v(n,0);
  // bool flag[n];
  // cout << "debug" << endl;
  rep(i,n) {
    // flag[i] = false;
    rep(j,n-1) {
      cin >> k;
      a[i][j] = k-1;
    }
    a[i][n-1] = -1;
  }
  // cout << "debug" << endl;
  bool today[n];
  int count = 0, days = 0;
  while(count < n*(n-1)/2) {
    days++;
    // cout << days << endl;
    for(int i = 0; i < n; i++) {
      today[i] = false;
    }
    rep(i,n) {
      // if(days == 4 && flag[i] == true)  cout << i << " :: " << flag[i] << endl;
      if(today[i] == true) continue;
      if (a[a[i][v[i]]][v[a[i][v[i]]]] == i && a[i][v[i]] > i && today[a[i][v[i]]] == false/* && flag[i] == false && flag[a[i][v[i]]] == false*/) {
        today[i] = true; today[a[i][v[i]]] = true;
        count++;
        // cout << i << " VS " << a[i][v[i]] << ", count = " << count << ", days = " << days << endl;
        // if(v[a[i][v[i]]] < n-1)
        v[a[i][v[i]]]++;
        // else {flag[a[i][v[i]]] = true;
        // if(v[i] < n-1)
        v[i]++;
        // else flag[i] = true;
      }
    }
    rep(i,n) {
      if(today[i]) break;
      if(i == n-1) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  cout << days << endl;
}
