#include <openacc.h>

#include <iostream>

using namespace std;

int main() {
  double a[1000];
#pragma acc parallel loop // GPUDA. Bilgi gpu dan alinmiyor
  for (int i = 0; i < 1000; i++) {
    a[i] = i;
  }

  // CPUDA. Alinsada burda override edilir
  for (int i = 0; i < 1000; i++) {
    a[i] = 3 * i;
  }
  for (int i = 0; i < 6; i++) cout << a[i] << " ";
  // 0 3 6 9 12 15
  cout << endl;
}

#pragma omp parallel for schedule(dynamic) reduction(c:sum)