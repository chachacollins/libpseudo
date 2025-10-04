CC ?= gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Werror
INCDIR = include
BUILDDIR = build
FILES = src/tgc.c

$(BUILDDIR)/libpseudo.a: $(FILES) 
	mkdir -p $(BUILDDIR)
	$(CC) -O3 $(FILES) -c $(CFLAGS) -o $(BUILDDIR)/libpseudo.o -I$(INCDIR)
	ar rcs $(BUILDDIR)/libpseudo.a $(BUILDDIR)/libpseudo.o
