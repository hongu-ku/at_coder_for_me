#include <iostream>
#include <string>
using namespace std;
int main(){
  string S;
  int a=0,b=0,c=0,d=0,r;cin>>S;
  for (size_t i = 0; i < S.length(); i++) {
    if(i%2) {
      if(S[i] == '0') a++;
      else b++;
    } else {
      if(S[i]=='0') c++;
      else d++;
    }
  }
  cout<<(a+d<b+c?a+d:b+c);
}
