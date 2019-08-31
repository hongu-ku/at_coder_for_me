#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define CON 1000000000000
#define SIX 1000000
using namespace std;

int h,w;
char maze[500][500]; //迷路
bool reached[500][500]; // 到達できるか

void search(int x, int y) {
// 迷路の外側か壁の場合は何もしない
if (x < 0 || h <= x || y < 0 || w <= y || maze[x][y] == '#') return;
// 以前に到達していたら何もしない
if (reached[x][y]) return;

reached[x][y] = true;

// 4方向を試す
search(x+1, y);
search(x-1, y);
search(x, y+1);
search(x, y-1);
}

int main() {
  cin >> h >> w;
  string a,s = "No";
  int startx, starty, goalx, goaly;
  for (int i = 0; i < h; i++) {
    cin >> a;
    for (int j = 0; j < w; j++) {
      reached[i][j] = false;
      maze[i][j] = a[j];
      if(a[j] == 's') {
        startx = i;
        starty = j;
      } else if(a[j] == 'g') {
        goalx = i;
        goaly = j;
      }
    }
  }
  search(startx, starty);
  if(reached[goalx][goaly]) s = "Yes";
  cout << s << endl;

}
