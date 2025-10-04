CC = cc
CFLAGS = -O3 -Wall -Wextra -Wpedantic -std=c11 -Werror -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TESTS = $(wildcard test/*.c)
TEST_BINS = $(TESTS:test/%.c=build/%)

build/libpseudo.a: $(OBJ)
	ar rcs $@ $^

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/%: test/%.c build/libpseudo.a
	@mkdir -p build
	$(CC) $(CFLAGS) $< build/libpseudo.a -o $@

test: $(TEST_BINS)
	@echo "Running tests..."
	@for test in $(TEST_BINS); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done
	@echo "All tests passed!"

clean:
	rm -rf build

.PHONY: clean test
