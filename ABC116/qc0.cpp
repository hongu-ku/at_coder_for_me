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
  for (int i = 0; i < a.length(); i++) {
    if(atoi(a[a.length() - 1 - i]) + 1 == 3) {
      a[a.length() - 1 - i] = 0;
    } else if(atoi(a[a.length() - 1 - i]) + 1 == 2){
      a[a.length() - 1 - i] = 2;
      break;
    } else {
      a[a.length() - 1 - i] = 1;
      break;
    }
  }
  return a;
}

int main() {
  long long n;
  Radix r;
  cin >> n;
  string s = r.to(n,3);
  // s = to_string(r.to(n,3));
  cout << r.to(n,3) << endl;
  cout << s << endl;
  return 0;
}
