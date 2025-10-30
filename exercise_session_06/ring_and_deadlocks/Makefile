CC      ?= cc          
CFLAGS  ?= -O3 -Wall -Wextra
TARGETS = ring_1 ring_2 ring_3 ring_1_deadlock

all: $(TARGETS)
%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f $(TARGETS)
