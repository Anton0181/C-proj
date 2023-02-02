#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "search.h"
int main(int argc, char** argv) {
	double x[1000], y[1000];
	int len = 0;
	double start, end, step;
	search(argc, argv, &start, &end, &step);
	FILE* fp = fopen("coordinate.txt", "w");
	for (int i = 0; i < 1000 && start < end; i++) {
		x[i] = start + step;
		start += step;
		len++;
		//j++;
	}

	for (int i = 0; i < len; i++) {

		y[i] = pow(x[i], 2);
	}

	for(int i =0; i< len; i++){
		fprintf(fp, "%.2lf %.2lf\n", x[i], y[i]);
	}
	fclose(fp);

	FILE* gnuplotPipe = _popen("gnuplot -presistent", "w");
	fprintf(gnuplotPipe, "plot 'coordinate.txt'\n");
	fprintf(gnuplotPipe, "exit");
	_pclose(gnuplotPipe);



	//Read argv and write in text file
	/*int res = 0;
	char* filename = argv[argc - 1];
	FILE* fp = fopen(filename, "w");
	for (int i = 1; i < argc - 1; i++) {
		printf("%s\n", argv[i]);
	}
	


	for (int i = 0; i < argc; i++) {
		fprintf(fp,"%s\n", argv[i]);
	}
	fseek(fp, 0, SEEK_END);
	res = ftell(fp);
	fclose(fp);

	printf("Size %ld byte\n", res);*/
}