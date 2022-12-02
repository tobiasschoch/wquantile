CC         = gcc.exe
CFLAGS     = -std=gnu99 -O3
R_DIR      = C:/"Program Files"/R/R-4.2.1
R_C_HEADER = $(R_DIR)/include
DLL_R      = $(R_DIR)/bin/x64/R.dll

# Link
OBJ = wquantile.o

wquantile.dll : $(OBJ)
	$(CC) -shared -o $@ $(DLL_R) $(OBJ)

# Compile
%.o : %.c
	$(CC) -Wall -pedantic -Wstrict-prototypes -I $(R_C_HEADER) -c -o $@ $< $(CFLAGS)

# Housekeeping
.PHONY: clean
clean:
	rm $(OBJ) wquantile.dll

