CC         := gcc
CFLAGS     := -std=gnu99 -O3 -fPIC
R_DIR      := /usr/lib64/R
R_C_HEADER := $(R_DIR)/include
DLL_R      := $(R_DIR)/lib/libR.so
RM         := rm -f

# Link
OBJ = wquantile.o

wquantile.so : $(OBJ)
	$(CC) -shared -o $@ $(DLL_R) $(OBJ)

# Compile
%.o : %.c
	$(CC) -Wall -pedantic -Wstrict-prototypes -I $(R_C_HEADER) -c -o $@ $< $(CFLAGS)

# Housekeeping
.PHONY: clean
clean:
	$(RM) $(OBJ) wquantile.so
