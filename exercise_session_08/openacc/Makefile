CC      = nvc
CFLAGS  = -O3 -acc -gpu=cc90

TARGET  = cpi_openacc
SOURCES = cpi_openacc.c gettime.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
