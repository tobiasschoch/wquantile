#include <stdio.h>
#include "wquantile.h"

static inline int equal(double, double);

double test(double*, double*, int); 

int case_1();  int case_2();  int case_3();  int case_4(); int case_5();  
int case_6();  int case_7();  int case_8();  int case_9(); int case_10();  
int case_11(); int case_12(); int case_13();  


/******************************************************************************\
|* main									      *| 
\******************************************************************************/
int main(){
   int errors = 0;

   // test of weighted quantile
   errors += case_1(); errors += case_2(); errors += case_3(); 
   errors += case_4(); errors += case_5(); errors += case_6(); 
   errors += case_7(); errors += case_8(); errors += case_9(); 
   errors += case_10(); errors += case_11(); errors += case_12(); 
   printf("wquantile: completed with %d errors\n", errors);
   
   // test of weighted quickselect
   int failure = 0, at;  
   for (at = 0; at < 20; ++at){ 
      double a[20] = {-0.77, -0.38, -2.03, -0.98,  0.24,   
      2.10, -0.38,  2.07,  1.02,  0.47,  
      -1.87, -1.23,  1.14,  0.00, -0.09,  
      1.79, -1.32, -0.27, -0.74, -1.07};  

      double s[20] = {-2.03, -1.87, -1.32, -1.23, -1.07,  
      -0.98, -0.77, -0.74, -0.38, -0.38,  
      -0.27, -0.09,  0.00,  0.24,  0.47,  
      1.02,  1.14,  1.79,  2.07,  2.10}; 

      double w[20]; 
      for (int i = 0; i < 20; ++i) w[i] = 1.0; 

      wselect0(a, w, 0, 19, at); 
      if (a[at] != s[at]){ 
	 failure += 1; 
	 printf("element %d is wrong\n", at); 
      } 
   } 
   if (failure == 0) printf("wselect: no failures\n"); 
   
   return 0;
}

/******************************************************************************\
|* test									      *| 
\******************************************************************************/
double test(double *array, double *weights, int n){
   double result = 0.0;
   double prob = 0.5; 
   wquantile(array, weights, &n, &prob, &result);
   return result;
}

// Case 1 
int case_1(){
   double result = 4.0;
   int n = 5;
   double x[] = {1.0,  2.0, 3.0, 4.0, 5.0};
   double w[] = {0.15, 0.1, 0.2, 0.3, 0.25};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 1: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;

} 

// Case 2 
int case_2(){
   double result = 2.5;
   int n = 4;
   double x[] = {1.0, 2.0, 3.0, 4.0};
   double w[] = {0.25, 0.25, 0.25, 0.25}; 
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 2: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;

} 

// Case 3 
int case_3(){
   double result = 2.5; 
   int n = 4;
   double x[] = {1.0,  2.0,  3.0,  4.0};
   double w[] = {0.49, 0.01, 0.25, 0.25};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 3: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 4 
int case_4(){
   double result = 2.0; 
   int n = 3;
   double x[] = {1.0, 2.0, 3.0};
   double w[] = {0.1, 0.1, 0.1 };
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 4: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 5 
int case_5(){
   double result = 1.5; 
   int n = 3;
   double x[] = {1.0, 2.0, 3.0};
   double w[] = {2.0, 1.0, 1.0};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 5: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 6 
int case_6(){
   double result = 1.0; 
   int n = 3;
   double x[] = {1.0, 2.0, 3.0};
   double w[] = {3.0, 1.0, 1.0};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 6: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 7 
int case_7(){
   double result = 1.5; 
   int n = 2;
   double x[] = {1.0, 2.0};
   double w[] = {1.0, 1.0};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 7: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 8 
int case_8(){
   double result = 2.9; 
   int n = 5;
   double x[] = {1.3, 5.1, 2.9, 1.9, 7.4};
   double w[] = {1.4, 0.9, 0.6, 1.2, 1.7};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 8: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 9 
int case_9(){
   double result = 3.7; 
   int n = 8; 
   double x[] = {4.2, 1.3, 7.4, 0.2, 4.6, 9.8, 5.5, 3.7};
   double w[] = {0.4, 2.1, 1.1, 1.6, 0.3, 0.9, 1.2, 1.7};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 9: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 10 
int case_10(){
   double result = 0.2; 
   int n = 7; 
   double x[] = {0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2};
   double w[] = {0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 10: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 11 
int case_11(){
   double result = 0.38; 
   int n = 20; 
   double x[] = {0.49, 0.36, 0.36, 0.18, 0.75, 0.33, 0.68, 0.82, 0.38, 0.75, 
	         0.61, 0.02, 0.57, 0.23, 0.56, 0.03, 0.45, 0.44, 0.36, 0.92};
   double w[] = {0.08, 0.22, 0.79, 0.84, 0.69, 0.84, 0.08, 0.87, 0.95, 0.27, 
		 0.9,  0.34, 0.75, 0.65, 0.02, 0.83, 0.32, 0.68, 0.92, 0.37};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 11: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 12 
int case_12(){
   double result = 0.51; 
   int n = 30; 
   double x[] = {0.64, 0.95, 0.05, 0.08, 0.32, 0.25, 0.58, 0.69, 0.88, 0.53, 
	         0.48, 0.58, 0.32, 0.52, 0.42, 0.69, 0.43, 0.91, 0.15, 0.27, 
	         0.31, 0.16, 0.56, 0.68, 0.58, 0.04, 0.51, 0.06, 0.18, 0.03};
   double w[] = {0.97, 0.2,  0.12, 0.01, 0.86, 0.29, 0.93, 0.96, 0.89, 0.03, 
	         0.24, 0.56, 0.81, 0.97, 0.48, 0.32, 0.33, 0.22, 0.8,  0.17, 
		 0.96, 0.75, 0.43, 0.24, 0.81, 0.4,  0.93, 0.43, 0.17, 0.13};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 12: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
} 

// Case 13 
int case_13(){
   double result = 0.36; 
   int n = 40; 
   double x[] = {0.19, 0.14, 0.15, 0.79, 0.36, 0.13, 0.44, 0.67, 0.44, 0.98,
	         0.2,  0.11, 0.78, 0.67, 0.28, 0.29, 0.99, 0.55, 0.34, 0.36, 
	         0.09, 0.13, 0.56, 0.19, 0.08, 0.46, 0.62, 0.98, 0.46, 0.37, 
	         0.09, 0.94, 0.84, 0.64, 0.18, 0.64, 0.78, 0.88, 0.17, 0.28};
   double w[] = {0.67, 0.39, 0.31, 0.06, 0.93, 0.21, 0.09, 0.29, 0.78, 0.42, 
	         0.79, 0.27, 0.77, 0.35, 0.11, 0.99, 0.05, 0.39, 0.34, 0.97, 
	         0.82, 0.4,  0.09, 0.77, 0.28, 0.03, 0.63, 0.67, 0.1,  0.3, 
	         0.85, 0.44, 0.66, 0.52, 0.15, 0.4,  0.82, 0.66, 0.21, 0.72};
   double m = test(x, w, n);
   if (equal(m, result) == 0) {
      printf("error, case 13: %.2f instead of %.2f\n", m, result);
      return 1;
   } else return 0;
}

/******************************************************************************\
|* equal: check whether two doubles are equal using Knuth's notion of      *|
|* essential equality							      *| 
\******************************************************************************/
static inline int equal(double a, double b)
{
   return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : 
      fabs(a)) * DBL_EPSILON);
} 
