#include <iostream>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define SORT_DOWN(v, n) sort(v, v+n, greater<int>());
#define VSORT_DOWN(v) sort(v.begin(),v.end(), greater<int>());
#define INF 999999999
using namespace std;

int main() {
  int sosu[1000] = {2};
  int koho[55] = {};
  int index = 0;
  int num  = 3;
  while (koho[54] == 0 && sosu[999] == 0) {
    for (size_t i = 0; i < 1000; i++) {
      if (sosu[i] == 0 && num % 10 == 1) {
        sosu[i] = num;
        koho[index] = num;
        index++;
        break;
      } else if (sosu[i] == 0) {
        sosu[i] = num;
        break;
      } else if (num % sosu[i] == 0) {
        break;
      }
    }
    num++;
  }
  int n;
  cin >> n;
  for (size_t i = 0; i < n-1; i++) {
    cout << koho[i] << " ";
  }
  cout << koho[n-1] << endl;
}
