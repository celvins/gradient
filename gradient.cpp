//============================================================================
// name        : gradient.cpp
// Author      : 
// Version     :
// Copyright   : Celvins
// Description : gradient
//============================================================================

#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
using namespace std;
//
//Ñòðóêòóðà ôàéëà: epsilon step n x[i] ... x[n - 1]
//
int main( void ){
	FILE *file;
	file = fopen("config.txt", "r");
	double step = 0, epsilon = 0, finish_point = 0, start_point = 0;
	int n = 0, i = 0, iter = 0;
	fscanf(file, "%lf %lf %d", &epsilon, &step, &n);
	double *x = new double[n];
	double *grad = new double[n];
	for(i = 0; i < n; i++){
		fscanf(file, "%lf", &x[i]);
	}
	fclose(file);
	for( ; ; ){
		iter += 1;
		printf("%lf %lf %d\n", step, f(x), iter);
		for (i = 0; i < n; i++){
			grad[i] = gradi(x, i);
		}
		double normi = norm(x);
		start_point = f(x);
		for (i = 0; i < n; i++){
			x[i] -= step * (grad[i] / normi);
		}
		finish_point = f(x);
		if (finish_point > start_point){
			if (step <= epsilon){
				break;
			}
			else{
				step /= 10;
			}
		}
	}
	fclose(file);
	delete []x;
	delete []grad;
	return 0;
}
