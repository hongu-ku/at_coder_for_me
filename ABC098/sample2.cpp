#include <iostream>
using namespace std;

int main() {
  float airSpeed = 5.32;
  char array[4];

  (float*)array = &airSpeed;

  // for (size_t i = 0; i < 4; i++) {
  //    = &airSpeed + i;
  //   cout << &airSpeed + i << endl;
  // }
  cout << &airSpeed << endl;
}
