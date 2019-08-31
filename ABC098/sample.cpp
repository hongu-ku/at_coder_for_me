#include<iostream>
using namespace std;

int main() {
  char name[] = "hongu";
  char* namae = "hongu";
  cout << "name: " << name << '\t' << "namae: " << namae << endl;
  *name = 'u';
  *(name+1) = 'e';
  namae = "India";
  cout << "name: " << name << '\t' << "namae: " << namae << endl;
}
