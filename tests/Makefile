# determine OS: Linux vs. Windows (mingw)
SYS := $(shell gcc -dumpmachine)

ifneq (, $(findstring mingw, $(SYS)))
	# Windows MinGW 
	CC		= C:/Rtools/mingw64/bin/gcc.exe
	CFLAGS		= -std=gnu99 -O2
	R_C_HEADER	= C:/"Program Files"/R/R-4.0.2/include
	DLL_BLAS	= C:/"Program Files"/R/R-4.0.2/bin/x64/Rblas.dll 
	DLL_LAPACK	= C:/"Program Files"/R/R-4.0.2/bin/x64/Rlapack.dll 
	DLL_R		= C:/"Program Files"/R/R-4.0.2/bin/x64/R.dll
else
	# Linux 
	CC			= gcc 
	CFLAGS		= -g -std=gnu99 -O2
	R_C_HEADER	= /usr/share/R/include/
	DLL_BLAS	= /usr/lib/x86_64-linux-gnu/libblas.so
	DLL_LAPACK	= /usr/lib/x86_64-linux-gnu/liblapack.so
	DLL_R		= /usr/lib/R/lib/libR.so
endif

# link
ifneq (, $(findstring mingw, $(SYS)))
test: test.o wquantile.o 
	$(CC) $@.o $(DLL_R) wquantile.o -o test
else 
test: test.o wquantile.o 
	$(CC) $@.o -L $(DLL_R) wquantile.o -lm -lR -o test.out
endif

# compile
wquantile.o: wquantile.c 
	$(CC) -Wall --pedantic -I $(R_C_HEADER) -c $*.c $(CFLAGS) 

# compile
test.o: test.c 
	$(CC) -I $(R_C_HEADER) -c $*.c $(CFLAGS) 

# housekeeping
.PHONY: clean
clean: 
	rm wquantile.o test.o
