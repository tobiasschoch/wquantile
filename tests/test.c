#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "cheat.h"
#include "cheats.h"
#include "wquantile.h"

#define PRECISION 1.0e-8

/******************************************************************************\
|* NOTE: make sure to also test diferent values for the macros _medium_array  *|
|* _large_array; in particular, test smaller values for _medium_array because *|
|* otherwise we are testing only intersertion sort...                         *|
\******************************************************************************/

/******************************************************************************\
|* TEST WEIGHTED MEDIAN                                                       *|
\******************************************************************************/
CHEAT_DECLARE(
	double weighted_median(double *array, double *weights, int n) {
		double result = 0.0;
		double prob = 0.5;
		wquantile(array, weights, &n, &prob, &result);
		return result;
	}
)

CHEAT_DECLARE(
	double weighted_quantile(double *array, double *weights, double prob,
            int n) {
		double result = 0.0;
		wquantile(array, weights, &n, &prob, &result);
		return result;
	}
)

CHEAT_TEST(median_case_1,
	int n = 5;
	double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double w[] = {0.15, 0.1, 0.2, 0.3, 0.25};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 4.0, PRECISION);
)

CHEAT_TEST(median_case_2,
	int n = 4;
	double x[] = {1.0, 2.0, 3.0, 4.0};
	double w[] = {0.25, 0.25, 0.25, 0.25};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 2.5, PRECISION);
)

CHEAT_TEST(median_case_3,
	int n = 4;
	double x[] = {1.0,  2.0,  3.0,  4.0};
	double w[] = {0.49, 0.01, 0.25, 0.25};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 2.5, PRECISION);
)

CHEAT_TEST(median_case_4,
	int n = 3;
	double x[] = {1.0, 2.0, 3.0};
	double w[] = {0.1, 0.1, 0.1 };
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 2.0, PRECISION);
)

CHEAT_TEST(median_case_5,
	int n = 3;
	double x[] = {1.0, 2.0, 3.0};
	double w[] = {2.0, 1.0, 1.0};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 1.5, PRECISION);
)

CHEAT_TEST(median_case_6,
	int n = 3;
	double x[] = {1.0, 2.0, 3.0};
	double w[] = {3.0, 1.0, 1.0};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 1.0, PRECISION);
)

CHEAT_TEST(median_case_7,
	int n = 2;
	double x[] = {1.0, 2.0};
	double w[] = {1.0, 1.0};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 1.5, PRECISION);
)

CHEAT_TEST(median_case_8,
	int n = 5;
	double x[] = {1.3, 5.1, 2.9, 1.9, 7.4};
	double w[] = {1.4, 0.9, 0.6, 1.2, 1.7};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 2.9, PRECISION);
)

CHEAT_TEST(median_case_9,
	int n = 8;
	double x[] = {4.2, 1.3, 7.4, 0.2, 4.6, 9.8, 5.5, 3.7};
	double w[] = {0.4, 2.1, 1.1, 1.6, 0.3, 0.9, 1.2, 1.7};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 3.7, PRECISION);
)

CHEAT_TEST(median_case_10,
	int n = 7;
	double x[] = {0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2};
	double w[] = {0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 0.2, PRECISION);
)

CHEAT_TEST(median_case_11,
	int n = 20;
	double x[] = {0.49, 0.36, 0.36, 0.18, 0.75, 0.33, 0.68, 0.82, 0.38, 0.75,
		 0.61, 0.02, 0.57, 0.23, 0.56, 0.03, 0.45, 0.44, 0.36, 0.92};
	double w[] = {0.08, 0.22, 0.79, 0.84, 0.69, 0.84, 0.08, 0.87, 0.95, 0.27,
	 0.9,  0.34, 0.75, 0.65, 0.02, 0.83, 0.32, 0.68, 0.92, 0.37};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 0.38, PRECISION);
)

CHEAT_TEST(median_case_12,
	int n = 30;
	double x[] = {0.64, 0.95, 0.05, 0.08, 0.32, 0.25, 0.58, 0.69, 0.88, 0.53,
		 0.48, 0.58, 0.32, 0.52, 0.42, 0.69, 0.43, 0.91, 0.15, 0.27,
		 0.31, 0.16, 0.56, 0.68, 0.58, 0.04, 0.51, 0.06, 0.18, 0.03};
	double w[] = {0.97, 0.2,  0.12, 0.01, 0.86, 0.29, 0.93, 0.96, 0.89, 0.03,
		 0.24, 0.56, 0.81, 0.97, 0.48, 0.32, 0.33, 0.22, 0.8,  0.17,
	 0.96, 0.75, 0.43, 0.24, 0.81, 0.4,  0.93, 0.43, 0.17, 0.13};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 0.51, PRECISION);
)

CHEAT_TEST(median_case_13,
	int n = 40;
	double x[] = {0.19, 0.14, 0.15, 0.79, 0.36, 0.13, 0.44, 0.67, 0.44, 0.98,
		 0.2,  0.11, 0.78, 0.67, 0.28, 0.29, 0.99, 0.55, 0.34, 0.36,
		 0.09, 0.13, 0.56, 0.19, 0.08, 0.46, 0.62, 0.98, 0.46, 0.37,
		 0.09, 0.94, 0.84, 0.64, 0.18, 0.64, 0.78, 0.88, 0.17, 0.28};
	double w[] = {0.67, 0.39, 0.31, 0.06, 0.93, 0.21, 0.09, 0.29, 0.78, 0.42,
		 0.79, 0.27, 0.77, 0.35, 0.11, 0.99, 0.05, 0.39, 0.34, 0.97,
		 0.82, 0.4,  0.09, 0.77, 0.28, 0.03, 0.63, 0.67, 0.1,  0.3,
		 0.85, 0.44, 0.66, 0.52, 0.15, 0.4,  0.82, 0.66, 0.21, 0.72};
	double m = weighted_median(x, w, n);
	cheat_assert_double(m, 0.36, PRECISION);
)

/******************************************************************************\
|* TEST WEIGHTED QUICKSELECT                                                  *|
\******************************************************************************/
CHEAT_TEST(quick_select,
	int at;
	double weights[20];
		for (int i = 0; i < 20; i++)
			weights[i] = 1.0;

	for (int at = 0; at < 20; at++) {
		double data[20] = {-0.77, -0.38, -2.03, -0.98, 0.24, 2.10, -0.38, 2.07,
			1.02,  0.47, -1.87, -1.23,  1.14,  0.00, -0.09, 1.79, -1.32, -0.27,
			-0.74, -1.07};

		double result[20] = {-2.03, -1.87, -1.32, -1.23, -1.07, -0.98, -0.77,
			-0.74, -0.38, -0.38, -0.27, -0.09,  0.00,  0.24,  0.47, 1.02,  1.14,
			1.79, 2.07,  2.10};

		wselect0(data, weights, 0, 19, at);
		cheat_assert_double(data[at], result[at], PRECISION);
	}
)
/******************************************************************************\
|* TEST MINIMALISTIC CASES                                                    *|
\******************************************************************************/
CHEAT_TEST(mini_case_1_low,
	int n = 2;
	double x[] = {2.0, 1.0};
	double w[] = {1.0, 1.0};
	double m = weighted_quantile(x, w, 0.1, n);
	cheat_assert_double(m, 1, PRECISION);
)

CHEAT_TEST(mini_case_1_hi,
	int n = 2;
	double x[] = {2.0, 1.0};
	double w[] = {1.0, 1.0};
	double m = weighted_quantile(x, w, 0.9, n);
	cheat_assert_double(m, 2, PRECISION);
)
