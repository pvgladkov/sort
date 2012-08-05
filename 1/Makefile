CC      = g++

all: bubble clean

bubble: bubble.o
	$(CC) -o $@ $^ $(LDFLAGS)

bubble.o: bubble.cpp 
	$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm bubble