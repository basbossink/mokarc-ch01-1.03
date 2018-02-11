CFLAGS+=-Wall -Wextra -Werror -pedantic -std=c11
SRC_DIR:=src
TEST_DIR:=tests
OUTPUT_DIR:=build
SOURCES:=$(wildcard $(SRC_DIR)/*.c)
TEST_SOURCES:=$(wildcard $(TEST_DIR)/*.c)
OBJECTS:=$(SOURCES:.c=.o)
TEST_OBJECTS:=$(TEST_SOURCES:.c=.o)
ALL_OBJECTS:=$(OBJECTS) $(TEST_OBJECTS)
DEPS:=$(ALL_OBJECTS:.o=.d)
TEST_EXECUTABLE:=$(OUTPUT_DIR)/test
EXECUTABLE:=$(OUTPUT_DIR)/temp_table

all: compile
	./$(TEST_EXECUTABLE)
	./$(EXECUTABLE)
	./$(EXECUTABLE) --celsius

compile: $(TEST_EXECUTABLE) $(EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS) | $(OUTPUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $^
-include $(DEPS)

$(EXECUTABLE): $(OBJECTS) main/main.o | $(OUTPUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $^
-include $(DEPS)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

lint: clean
	scan-build --use-cc=/usr/local/bin/clang-5.0 -o /tmp gmake compile

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -MF $*.d -c $< -o $@

.PHONY: clean all lint compile

clean:
	rm -rf $(OUTPUT_DIR) $(ALL_OBJECTS) $(DEPS)
