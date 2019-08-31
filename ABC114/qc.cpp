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

class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};

string add(string a){
  string s = a;
  for (int i = 0; i < a.length(); i++) {
    if(atoi(s[a.length() - 1 - i]) + 1 == 3) {
      s[s.length() - 1 - i] = 0;
      if(i = s.length()-1) s="1"+s;
    } else if(atoi(a[a.length() - 1 - i]) + 1 == 2){
      s[s.length() - 1 - i] = 2;
      break;
    } else {
      s[s.length() - 1 - i] = 1;
      break;
    }
  }
  return s;
}

bool check(string s){
  bool a[3] = {false,false,false};
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == 0) a[0] = true;
    else if(s[i] == 1) a[1] = true;
    else a[2] = true;
  }
  for (size_t i = 0; i < 3; i++) {
    if(!a[i]) return false;
  }
  return true;
}

int main() {
  long long n;
  Radix r;
  cin >> n;
  string s = "0";
  string max = r.to(n,3);
  for ( i = 0; i < count; i++) {
    /* code */
  }
  // s = to_string(r.to(n,3));
  cout << r.to(n,3) << endl;
  cout << s << endl;
  return 0;
}
