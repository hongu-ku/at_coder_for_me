#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
  std::vector<int> v;
  int c[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cin >> c[i][j];
    }
  }
  int a[3],b[3];
  for (int a0=-100000; a0<c[0][0]; a0++) {
    for (int j = 0; j<3; j++) {
      b[j] = c[0][j] - a0;
    }
    if (c[1][0]-b[0] == c[1][1]-b[1] && c[1][1]-b[1] == c[1][2]-b[2] && c[2][0]-b[0] == c[2][1]-b[1] && c[2][1]-b[1] == c[2][2]-b[2]){
      cout << "Yes" << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";
}
