# wquantile

## Overview
The (minimalistic) library `wquantile` consists of the following two C99 functions: 

**1. weighted quantile**
```C
void wquantile(double *array, double *weights, int *n, double *prob, double *result)
```
where

   * `array` and `weights` are arrays of size `n`, 
   * `prob` specifies the quantile,
   * on return, the result is in `result`; 

**2. selection of the k-th largest element (k-th order statistic)**

```C
void wselect0(double *array, double *weights, int lo, int hi, int k)
``` 

where 

   * `k` specifies the k-th order statistic (zero indexing),
   * `lo` and `hi` (zero indexing) specify the range of elements to be considerd, i.e. `array[lo..hi]` and `weights[lo..hi]`,
   * on return, the k-th order statistic is located in `array[k]`. 

## Details
The functions build on a weighted version of the quickselect algorithm with the Bentley and McIlroy (1993) 3-way partitioning scheme. For very small arrays, we use selection sort.   

For equal weighting, i.e. when all elements in `weights` are equal, `wquantile` computes quantiles of type 2 in Hyndman and Fan (1996). 

## Compilation
See makefiles in `/src`.  

## References 
Bentley, J.L. and D.M. McIlroy (1993). Engineering a Sort Function, *Software - Practice and Experience* 23, pp. 1249-1265.  
Hyndman, R.J. and Y. Fan (1996). Sample Quantiles in Statistical Packages, *The American Statistician* 50, pp. 361-365.
