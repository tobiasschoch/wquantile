# `wquantile`: Weighted quantile and selection of the k-th largest element

## About
The (minimalistic) library `wquantile` consists of the following two C99/C11
functions:

**1. weighted quantile**
```C
void wquantile(double *array, double *weights, int *n, double *prob,
double *result)
```
where

   * `array` and `weights` are arrays of size `n`,
   * `prob` specifies the quantile, i.e. a value in the interval [0,1],
   * on return, the variable `result` has the estimated quantile;

**2. selection of the k-th largest element (k-th order statistic)**

```C
void wselect0(double *array, double *weights, int lo, int hi, int k)
```

where

   * `k` specifies the k-th order statistic (zero indexing),
   * `lo` and `hi` (zero indexing) specify the range of elements to be
considered, i.e. `array[lo..hi]` and `weights[lo..hi]`,
   * on return, the k-th order statistic is located in `array[k]`.

### Details
The functions build on a weighted version of the quickselect algorithm with
the [Bentley and McIlroy](#References) (1993) 3-way partitioning scheme.
For very small arrays, we use insertion sort.

For equal weighting, i.e. when all elements in `weights` are equal,
`wquantile` computes quantiles of type 2 in [Hyndman and Fan](#References)
(1996).

### Tuning
(Weighted) quicksort is efficient for large arrays. Though, its overhead
can be severe for small arrays; hence, we use insertion sort for small
arrays; cf. [Bentley and McIlroy](#References) (1993). The size threshold
below which insertion sort is used can be specified by setting the
preprocessor macro `_n_quickselect` at compile time. By default,
`_n_quickselect` is set to 40. We came up with this choice by a series
of benchmarks using [Google Benchmark](https://github.com/google/benchmark)
on an ordinary laptop with an Intel i7-8550U processor (released 2017/2018,
cache size: L1: 256 KB, L2: 1 MB, L3: 8 MB).

## Build/ Installation
The code is compiled against the header `R.h` of the R software
([R Core Team](#References), 2021); see makefile in the folder `/src`.

The library `wquantile` can also be built *without* depending on the R
software. To this end, remove the header file `R.h` and include instead
the header files: `<math.h>`, `<float.h>`, `<string.h>`, and `<stdlib.h>`.
In addition, make the following substitutions in the function `wquantile`:
`calloc` for `Calloc`, `memcpy` for `Memcpy`, and `free` for `Free`.

## Community guidelines

#### Submitting an issue
If you have any suggestions for feature additions or any problems with
the software that you would like addressed with the development community,
please submit an issue on the Issues tab of the project GitHub repository.
You may want to search the existing issues before submitting, to avoid
asking a question or requesting a feature that has already been discussed.

#### How to contribute
If you are interested in modifying the code, you may fork the project for
your own use, as detailed in the GNU GPL License we have adopted for the
project. In order to contribute, please contact the developers via Tobias
Schoch at gmail dot com (the names are separated by a dot) after making
the desired changes.

#### Asking for help
If you have questions about how to use the software, or would like to seek
out collaborations related to this project, you may contact Tobias Schoch
(see contact details above).


## References

Bentley, J.L. and D.M. McIlroy (1993). Engineering a Sort Function,
*Software - Practice and Experience* 23, pp. 1249-1265.

Hyndman, R.J. and Y. Fan (1996). Sample Quantiles in Statistical
Packages, *The American Statistician* 50, pp. 361-365.

R Core Team (2021). R. A language and environment for statistical
computing. R Foundation for Statistical Computing, Vienna, Austria.
URL [https://www.R-project.org](https://www.R-project.org).
