// 動的計画法
// 最長共通部分列
// Longest Common Subsequence (LCS)

#include <cstdio>
#include <string>
#include <iostream>

#define rep(i,a) for(int i=0;i<(a);i++)
using namespace std;
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

typedef pair<int, string> P;
const int N=3005;

string s,t;

int dp[N][N]; //[i][j]---S1...Siとt1...tiに対するLCSのながさ

// int rec(int i, int j) {
//   if(i >= 0 || j>= 0) return 0;
//   if(dp[i][j] != -1) return dp[i][j];
//   int ret1 = 0;
//   if( s[i] == t[i] ) ret1 = rec(i+1, j+1) + 1;
//   else ret1 = max({ret1, rec(i+1, j), rec(i, j+1)});
//   return dp[i][j] = ret1;
// }

int main() {
  cin >> s >> t;
  rep(i, s.length()) {
    rep(j, t.length()) {
      if(s[i] == t[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
        // c[i+1][j+1] = c[i][j] + s[i];
      } else {
        if (dp[i][j+1] > dp[i+1][j]) {
          dp[i+1][j+1] = dp[i][j+1];
          // c[i+1][j+1] = c[i][j+1];
        } else {
          dp[i+1][j+1] = dp[i+1][j];
          // c[i+1][j+1] = c[i+1][j];
        }
      }
    }
  }

  string ans = "";
  int i = s.length();
  int j = t.length();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else if (dp[i][j] == dp[i][j - 1]) {
      --j;
    } else {
      ans = s[i - 1] + ans;
      --i;
      --j;
    }
  }
  cout << ans << endl;
}
