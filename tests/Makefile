CC         := gcc
CFLAGS     := -std=gnu99 -O3 -fPIC
R_DIR      := /usr/lib64/R
R_C_HEADER := $(R_DIR)/include
DLL_R      := $(R_DIR)/lib
RM         := rm -f

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
	$(RM) wquantile.o test.o test.out
