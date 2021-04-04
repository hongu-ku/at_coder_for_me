#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s = "15";
  int num = atoi(s.c_str());
  string tt = to_string(num);
  cout << tt << endl;
}