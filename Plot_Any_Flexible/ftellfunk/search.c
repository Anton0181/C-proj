#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void search(int argc, char** argv, double* start, double* end, double* step) {
	char* upper = "-ub";
	char* lower = "-lb";
	char* stepA = "-s";
	int check = 0;
	int indUpper, indLower, indStep;
	
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], upper) == 0) {
			*end = atof(argv[i + 1]);
		}
		else if (strcmp(argv[i], lower) == 0) {
			*start = atof(argv[i + 1]);
		}
		else if (strcmp(argv[i], stepA) == 0) {
			*step =atof(argv[ i+1]);
		}
		
	}
	


}