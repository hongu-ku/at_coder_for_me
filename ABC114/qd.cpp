#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int soinsu[] = {7,11,13,17,19,23,29,31,37,41,43};
  int a[3]={2,3,5};
  // for(int i=0;i<soinsu.size();i++){
  //
  // }
  int n,temp;
  int num4=0,num2=0,num14=0,num24=0,num74=0,num4_2=0,num2_2=0;
  cin >> n;
  int num[n];
  for (size_t i = 0; i < n; i++) {
    num[i] = 0;
  }
  for (size_t i = 1; i <= n; i++) {
    temp = i;
    for (size_t j = 2; j < n; j++) {
      while(temp%j==0){
        num[j-1] += 1;
        temp = temp/j;
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    if(num[i] >= 4)num4++;
    else if(num[i] >= 2) num2++;
    if(num[i] >= 14) num14++;
    else if(num[i] >= 4)num4_2++;
    if(num[i] >= 24) num24++;
    else if(num[i] >= 2) num2_2++;
    if(num[i] >= 74) num74++;
  }
  int result = 0;
  result += num4 * (num4-1) / 2 * num2;
  result += num4 * (num4-1) * (num4-2) /2;
  result += num14 * num4_2;
  result += num14 * (num14-1);
  result += num24 * num2_2;
  result += num24 * (num24-1);
  result += num74;
  cout << result << endl;
}
