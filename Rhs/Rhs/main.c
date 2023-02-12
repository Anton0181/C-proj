#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void generate_data(double, double, double, int);
void gnuplot();
double RHS(double y, double t);

int main() {

	int max_size = 5000;
	double step_size = 1e-3;
	//printf("%lf", step_size);
	double y0 = 1;
	double t0 = 0;
	generate_data(y0, t0, step_size, max_size);
	gnuplot();
	return 0;
	
	
}
double RHS(double y, double t) {
	return y;

}
void generate_data(double y0, double t0, double step_size, int max_size ) {
	double* y = (double*)malloc(max_size * sizeof(double));
	double* t = (double*)malloc(max_size * sizeof(double));
	double f = 0;
	FILE* fp;
	fp = fopen("y_t.txt", "w");

	for (int i = 0; i < max_size; i++) {
		
		y[i] = y0;
		t[i] = t0;
		f = RHS(y[i], t[i]);
		fprintf(fp, "%lf %lf\n", t[i], y[i]);
		y0 = y0 + (step_size * y0);
		t0 = t0 + step_size;
	}
	fclose(fp);
}

void gnuplot() {
	FILE* gnuplotPipe = _popen("gnuplot -presistent", "w");

	fprintf(gnuplotPipe, "plot 'y_t.txt'\n");

	fprintf(gnuplotPipe, "exit");
	_pclose(gnuplotPipe);
}