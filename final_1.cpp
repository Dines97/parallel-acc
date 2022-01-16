#include <openacc.h>

#include <iostream>

using namespace std;

int main() {
  double a[1000];
#pragma acc parallel loop
  for (int i = 0; i < 1000; i++) {
    a[i] = 3 * i;
  }
  for (int i = 0; i < 1000; i++) {
    a[i] = 5 * i;
  }
  for (int i = 0; i < 6; i++) cout << a[i] << " ";
  cout << endl;
}