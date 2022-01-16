#include <openacc.h>

#include <iostream>

using namespace std;
// g++ -O2 -ffast-math -fopenacc -fopt-info-all-omp -fcf-protection=none -foffload=nvptx-none final_3.cpp
int main() {
	//double t1 = omp_get_wtime(), t2;

	int n = 8192, m = 8192;
	int iter = 0;
	double error = 1;
	double static A[8192][8192], Anew[8192][8192];

	int tol = 0.000001;
	int iter_max = 10000;


	while (error > tol && iter < iter_max) {
		error = 0.0;
//#pragma acc kernels
		#pragma acc parallel loop collapse(2)
		for (int j = 0; j < n - 1; ++j) {
			for (int i = 0; i < m - 1; ++i) {
				Anew[j][i] = 0.25 * (A[j][i + 1] + A[j][i - 1] + A[j - 1][i] + A[j + 1][i]);
				error = max(error, abs(Anew[j][i] - A[j][i]));
			}
		}
//#pragma acc kernels
		#pragma acc parallel loop collapse(2)
		for (int j = 0; j < n - 1; ++j) {
			for (int i = 0; i < m - 1; ++i) {
				A[j][i] = Anew[j][i];
			}
		}
		iter++;
	}

	//t2 = omp_get_wtime();
	//cout << "Elapsed time: " << t2 - t1 << endl;
}
