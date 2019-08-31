#include <iostream>
#include <string>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int n,m;
  int x,y,newx,newy,oldx,oldy;
  x = 0;
  y = 0;
  int num=0;
  cin >> n >> m;
  string s;
  for(int i=1; i<n+1; i++) {
    cout << i << "だよ" << endl;
    for(int j=1; j<m+1; j++) {

      x = i;
      y = j;
      for(int k=0; ; k++) {
        if(x == 0 || y == 0){
          break;
        } /*else if(k == 100000) {
          num++;
          cout << '(' << i << ',' << j << ')' << endl;
          break;
        } */else {
          if(x<y) {
            s = to_string(x);
            reverse(s.begin(), s.end());
            newx = stoi(s);
            // newx= stoi(to_string(x).reverse());
            newy= y;
          } else {
            s = to_string(y);
            reverse(s.begin(), s.end());
            newy = stoi(s);
            // newy = stoi(to_string(y).reverse());
            newx = x;
          }
          if(newx < newy) {
            if(y == newy - newx) {
              num++;
              break;
            } else if(oldy == newy - newx && oldx == x && oldx != 0 && oldy != 0) {
              num++;
              cout << "Q(" << i << ',' << j << ')' << endl;
              break;
            } else {
              oldy = y;
              y = newy - newx;
            }
          } else {
            if(x == newx - newy){
              num++;
              cout << "Z(" << i << ',' << j << ')' << endl;
              break;
            } else if(oldx == newx -newy && oldy == y&& oldx != 0 && oldy != 0) {
              num++;
              cout << "P(" << i << ',' << j << ')' << endl;
              break;
            } else {
              oldx = x;
              x = newx - newy;
            }
          }
        }
        // cout << '(' << x << ',' << y << ')' << endl;
      }
    }
  }
  cout << num << endl;
}
