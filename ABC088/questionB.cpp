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
  int N,Alice,Bob;
  Alice = 0;
  Bob = 0;
  cin >> N;
  vector<int> v;
  int a;
  for (int i = 0; i<N; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0; i<v.size(); i++) {
    if(i % 2) {
      Bob+=v[i];
      // cout << v[i] << "\n";
    } else {
      Alice+=v[i];
      // cout << v[i] << "\n";
    }
  }
  cout << Alice - Bob << "\n";
}
