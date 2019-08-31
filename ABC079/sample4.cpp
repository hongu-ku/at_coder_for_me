#include <iostream>
#include <math.h>
#define PLUS 0x2B
#define MINUS 0x2D

using namespace std;

int pathsearch(int from, int** c) {
  // fromが1~9であることを前提
  int point = 20;
  int temp;
  for (int a=0; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      for (int cc = 0; cc < 10; cc++) {
        for (int d = 0; d < 10; d++) {
          for (int e=0; e < 10; e++) {
            for (int f = 0; f < 10; f++) {
              for (int g=0; g < 10; g++) {
                for (int h = 0; h < 10; h++) {
                  temp = c[from][a]+c[a][b]+c[b][cc]+c[cc][d]+c[d][e]+c[e][f]+c[f][g]+c[g][h]+c[h][1];
                  point = temp > point ? point : temp;
                }
              }
            }
          }
        }
      }
    }
  }
  return point;
}


int main () {
  int h,w;
  int c[10][10];
  // ポインタのポインタ
  int *B[10];
  cin >> h >> w;
  cin.get();
  int a[w][h];
  int point[10];


  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
    cin.get();
  }
  for (int i=0;i<10;i++) B[i] = c[i];
  cout << c[8][4] << " " << c[4][8] << endl;
  for (int i=0;i<10;i++) point[i] = pathsearch(i,B);
  int necessary = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> a[i][j];
      // 処理
      if (a[i][j] != -1 && a[i][j] != 1)
        necessary += point[a[i][j]];
    }
    cin.get();
  }
  cout << necessary << endl;

  return 0;
}
