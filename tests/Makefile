CC=cc
CFLAGS+=-Wall -Wextra -Werror -pedantic --std=c11
SRC_DIR:=../src
SOURCES:=$(wildcard $(SRC_DIR)/*.c)
TEST_SOURCES:=$(wildcard *.c)
OBJECTS:=$(SOURCES:.c=.o)
TEST_OBJECTS:=$(TEST_SOURCES:.c=.o)
OBJS:=$(OBJECTS)
OBJS+=$(TEST_OBJECTS)
DEPS:=$(OBJS:.o=.d)
EXECUTABLE:=test

all: $(EXECUTABLE)
	@./$(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
-include $(DEPS)


%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -MF $*.d -c $< -o $@

.PHONY: clean

clean:
	rm -f *.BAK $(OBJS) $(DEPS) $(EXECUTABLE)
