CC=cc
CFLAGS+=-Wall -Wextra -Werror -pedantic --std=c11
SRC_DIR:=../src
SOURCES:=$(wildcard $(SRC_DIR)/*.c)
TEST_SOURCES:=$(wildcard *.c)
OBJECTS:=$(SOURCES:.c=.o)
TEST_OBJECTS:=$(TEST_SOURCES:.c=.o)
EXECUTABLE:=test

all: $(SOURCES) $(TEST_SOURCES) $(EXECUTABLE)
	@./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.BAK $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE)
