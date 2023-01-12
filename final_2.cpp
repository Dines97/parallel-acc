#include <openacc.h>

#include <iostream>

using namespace std;

int main() {
  double a[1000];

// Bilgi gpu ya veriliyor
#pragma acc data copy(a)
  {
#pragma acc parallel loop // GPU
    for (int i = 0; i < 1000; i++) {
      a[i] = i;
    }

	// CPU da
    for (int i = 0; i < 1000; i++) {
      a[i] = 3 * i;
    }
  }//  Bilgi gpu dan aliniyor. Gpu dan alindigi icin en son cpu islemi override edilmis oluyor


  for (int i = 0; i < 6; i++) cout << a[i] << " ";

  // 0 1 2 3 4 5
  cout << endl;
}