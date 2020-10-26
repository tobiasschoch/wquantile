# some macros
CC		= C:/Rtools/mingw64/bin/gcc.exe
CFLAGS		= -std=c11 -O0
R_C_HEADER	= C:/"Program Files"/R/R-3.5.1/include
#BLAS_LIBS	= C:/"Program Files"/R/R-3.5.1/bin/x64/Rblas.dll 
#LAPACK_LIBS	= C:/"Program Files"/R/R-3.5.1/bin/x64/Rlapack.dll 
DLL_R		= C:/"Program Files"/R/R-3.5.1/bin/x64/R.dll

# link
wquantile: wquantile.o 
	$(CC) -shared -o $@.dll $@.o $(DLL_R) 

# compile
wquantile.o: wquantile.c 
	$(CC) -Wall -I $(R_C_HEADER) -c $*.c $(CFLAGS) 

# housekeeping (using make clean)
.PHONY: clean
clean: 
	rm wquantile.o 
