# wquantile

## Overview
The (minimalistic) library `wquantile` consists of the following two C99 functions: 
   * `wquantile`: weighted quantile, 
   * `wselect`: selection of the k-th largest element (order statistic). 

## Details
The functions build on a weighted version of the quickselect algorithm. We use the Bentley and McIlroy (1993) 3-way partitioning scheme. For very small arrays, we use selection sort instead of quickselect.   

## Compilation
See makefiles in `/src`.  

## References 
Bentley, J.L. and D.M. McIlroy (1993). Engineering a Sort Function, *Software - Practice and Experience* 23, pp. 1249-1265.  
