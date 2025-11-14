NVCC      = nvcc
NVCCFLAGS = -O3 -arch=sm_90

TARGET    = cpi_cuda
CU_SOURCES = cpi_cuda.cu
C_SOURCES  = gettime.c
OBJS       = cpi_cuda.o gettime.o

all: $(TARGET)

cpi_cuda.o: cpi_cuda.cu
	$(NVCC) $(NVCCFLAGS) -c cpi_cuda.cu -o cpi_cuda.o

gettime.o: gettime.c
	$(NVCC) $(NVCCFLAGS) -c gettime.c -o gettime.o

$(TARGET): $(OBJS)
	$(NVCC) $(NVCCFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

