# Linux
CC			= gcc
CFLAGS		= -g -std=gnu99 -O2
R_C_HEADER	= /usr/lib64/R/include
DLL_R		= /usr/lib64/R/lib

# link
test: test.o wquantile.o
	$(CC) $@.o -L $(DLL_R) wquantile.o -lm -lR -o test.out

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
