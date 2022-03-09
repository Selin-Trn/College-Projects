/*
 *
 *  Created on: Jan 5, 2022
 *      Author: Selin Turan
 * 
 * Note: "hata" means "error" in Turkish.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 250
#define C 5

typedef struct {
	int c[C];
	double x[N];
	double y[N];
	double error;
} equation;

equation newEquation(int c[C], double x[N]);
void computeY(equation* e);
double computeMSE(equation e1, equation e2);

int main(int argc, char* argv[]) {
	srand(time(0));
	equation equat;
	equation new_equat;
	equation * new_equat_pointer;
	new_equat_pointer = &new_equat;

	FILE* f = fopen(argv[1], "r");
	if (!f) {
		perror("Problem opening the file");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < N; i++)  {
		fscanf(f, "%lf,%lf\n", &equat.x[i], &equat.y[i]);
	}
	fclose(f);

	int c0[C] = { 1, 1, 1, 1, 1 };
	new_equat = newEquation(c0, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("If all the coefficients are 1, the error case: %lf\n", new_equat.hata);

	float error_rate[5]; // This array is to save the calculated error rates.
							// so that we can compare them and find the lowest one

	// These numbers are just to try the program with determined coefficient values.
	int c1[C] = { 6, 7, 5, 8, 4 };
	printf("Error ratio of c1: ");
	new_equat = newEquation(c1, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("%lf\n", new_equat.hata);
	error_rate[0] = new_equat.hata;

	int c2[C] = { 5, 3, 8, 7, 2 }; // After trying all the coefficients, we find that the closest coefficients are in c2.
	printf("c2 in hata orani: ");
	new_equat = newEquation(c2, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("%lf\n", new_equat.hata);
	error_rate[1] = new_equat.hata;

	int c3[C] = { 2, 9, 4, 7, 3 };
	printf("c3 in hata orani: ");
	new_equat = newEquation(c3, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("%lf\n", new_equat.hata);
	error_rate[2] = new_equat.hata;

	int c4[C] = { 3, 3, 9, 8, 2 };
	printf("c4 in hata orani: ");
	new_equat = newEquation(c4, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("%lf\n", new_equat.hata);
	error_rate[3] = new_equat.hata;

	int c5[C] = { 8, 7, 5, 1, 9 };
	printf("c5 in hata orani: ");
	new_equat = newEquation(c5, equat.x);
	computeY(new_equat_pointer);
	new_equat.hata = computeMSE(equat, new_equat);
	printf("%lf\n", new_equat.hata);
	error_rate[4] = new_equat.hata;

	int c_sirasi = 0;
	float min_hata = error_rate[0];
	for (int i = 0; i < C; i++) {
		if (min_hata > error_rate[i]) {
			min_hata = error_rate[i];
			c_sirasi = i+1;
		}
	}
	printf("With an error rate of %lf ", min_hata);
	printf("the array with the closest coefficients is: c%i\n\n", c_sirasi);


//	WE HAVE TWO SEPERATE WAYS TO FIND THE RIGHT COEFFICIENTS
//	IN ORDER TO PROPERLY SEE THE OUTPUT OF THE CODE ABOVE, TURN BOTH METHOD 1 AND METHOD 2 INTO COMMENTS 
	int correct_c[C];
//------------------------------------------------------------------------------- METHOD 1: RANDOM
	// We find the coefficients with randomly generated numbers
/*	while (new_equat.hata > 0.0000001) {
		for (int i = 0; i < 5; i++) {
			int r = 1 + (rand() % 9);
			correct_c[i] = r;
		}
		new_equat = newEquation(correct_c, q.x);hata oraný
		computeY(new_equat_pointer);
		new_equat.hata = computeMSE(q, new_equat);
		printf("%lf\n", new_equat.hata);
	}
	printf("The closest coefficients: ");
	for (int i = 0; i < C; i++) {
		printf("%d ", correct_c[i]);
	}
*/
//------------------------------------------------------------------------------- METHOD 2: DIGIT SEPERATING	
	// With this method, we will certainly reach the desired coefficients
	// When we "combine" all the coefficients into one single number, the highest value is 9999 and the lowest value is 11111
	// This is because we know that the coefficients are between 1 and 9.
/*		for (int i = 11111; i < 100000; i++) {
		int num = i;
		for (int k = C-1; k >= 0; k--) {
			correct_c[k] = num % 10;
			num = num/10;
		}
		for (int m = 0; m < 5; m++) {
			printf("%d ", correct_c[m]);
		}
		new_equat = newEquation(correct_c, equat.x);
		computeY(new_equat_pointer);
		new_equat.hata = computeMSE(equat, new_equat);
		printf("%lf\n", new_equat.hata);

		if (new_equat.hata <= 0.0000001) {
			break;
		}
	}
	printf("The closest coefficients: ");
		for (int i = 0; i < C; i++) {
			printf("%d ", correct_c[i]);
		}
*/
//-------------------------------------------------------------------------------
	printf("\nThe answer is 2 9 7 8 5 coefficients");
	return 0;
}


equation newEquation(int c[C], double x[N]) {
	equation temp;
	for (int i = 0; i < C; i++) {
		temp.c[i] = c[i];
	}
	for (int i = 0; i < N; i++) {
		temp.x[i] = x[i];
	}
	return temp;
}

void computeY(equation * e) {
	for (int i = 0; i < N; i++) {
		double tx = e->x[i]; //tx = tempx
		e->y[i] = (e->c[0] * pow(tx, 4)) + (e->c[1] * pow(tx, 3)) + (e->c[2] * pow(tx, 2)) + (e->c[3] * tx) + (e->c[4]);
	}
}

double computeMSE(equation e1, equation e2) {
	double mse = 0;
	for (int i = 0; i < N; i++) {
		mse = mse + pow((e1.y[i] - e2.y[i]), 2);
	}
	mse = pow(N, -1) * mse;
	return mse;
}

double calcMSE(int c[C], equation e1, equation e2, equation * e2P) {
	e2 = newEquation(c, e1.x);
	computeY(e2P);
	e2.hata = computeMSE(e1, e2);
	printf("%lf\n", e2.hata);
	return e2.hata;
}
