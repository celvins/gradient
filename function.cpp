/*
 * function.cpp
 *
 *  Created on: 09.06.2014
 *      Author: Àíäðàíèê
 */

#include "function.h"
#include <math.h>

double gradi(double* x , int index){
	switch (index){
	case 0:
		return -sin(x[0] + 1.23 * x[1]);
		break;
	case 1:
		return  2 * x[1] - 1.23 * sin(x[0] + 1.23 * x[1]);
		break;
	}
	return 0;
}

double f(double* x){
	return  x[1] * x[1] + cos(x[0] + 1.23 * x[1]);
}

double norm(double* x){
	return sqrt(pow(gradi(x, 0), 2) + pow(gradi(x, 1), 2));
}
