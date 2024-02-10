C_FLAGS					= -fPIC -Wall -Wextra -Werror
INCLUDE_C_FLAGS = -Iblst/bindings
ANEMOI_C_FILE		= anemoi.c
ANEMOI_H_FILE		= anemoi.h
ANEMOI_O_FILE		= anemoi.o

TEST_C_FILE			= test.c
TEST_O_FILE			= test.o
TEST_EXECUTABLE	= test

all: $(ANEMOI_O_FILE) $(TEST_O_FILE)

$(TEST_O_FILE): $(TEST_C_FILE) libblst.a
	$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDE_C_FLAGS)

$(ANEMOI_O_FILE): $(ANEMOI_C_FILE) libblst.a
	$(CC) $(C_FLAGS) -c $< -o $@ $(C_FLAGS) $(INCLUDE_C_FLAGS)

test: $(TEST_O_FILE) $(ANEMOI_O_FILE) libblst.a
	$(CC) -o $(TEST_EXECUTABLE) $(TEST_O_FILE) $(ANEMOI_O_FILE) $(INCLUDE_C_FLAGS) -Lblst/ -lblst
	./$(TEST_EXECUTABLE)

libblst.a:
	cd blst && ./build.sh

lint:
	clang-format -i $(ANEMOI_C_FILE) $(ANEMOI_H_FILE) $(TEST_C_FILE)

clean:
	rm -f $(ANEMOI_O_FILE) $(TEST_O_FILE)

fclean: clean
	rm -f $(TEST_EXECUTABLE)
