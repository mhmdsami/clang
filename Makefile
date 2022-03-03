CFLAGS=-Wall -g

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: clean build

build: ${BINS}

clean:
	@echo "Cleaning..."
	rm -rvf ${BINS}
