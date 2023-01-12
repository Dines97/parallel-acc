//
// Created by denis on 12.01.2023.
//


#include <iostream>

using namespace std;

int main() {

	int n;
	int **a, **b, **c;

#pragma omp parallel for schedule(dynamic) reduction(+:c)
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0.0;
			for (int k = i; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
