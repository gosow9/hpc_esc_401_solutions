CC = CC 
CFLAGS = -O3 -fopenmp
TARGET = race
SRC = race_1.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

