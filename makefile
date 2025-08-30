OBJ=obj
TARGET=test_mxcur
FLAGS_C=-O3
FLAGS_L=
TIME=/usr/bin/time
TIME_FORMATTING="Build took %E"
VALGRIND_OUT=$(TARGET)_valgrind

C_SOURCES=$(wildcard *.c)
H_SOURCES=$(wildcard *.h)
OBJECTS=$(patsubst %.c,$(OBJ)/%.o,$(C_SOURCES))

default: build

ifeq (leak_check,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

leak_check:
	valgrind --log-file=$(VALGRIND_OUT) --leak-check=full $(TARGET) $(RUN_ARGS)
	cat $(VALGRIND_OUT) | less

build:
	@$(TIME) --format=$(TIME_FORMATTING) make build_s2 --no-print-directory

build_s2: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -o $(TARGET) $(FLAGS_L)

$(OBJ)/%.o: %.c
	gcc -c $^ -o $@ $(FLAGS_C)

setup:
	mkdir $(OBJ)

clean:
	rm -r $(OBJ)
	mkdir $(OBJ)
