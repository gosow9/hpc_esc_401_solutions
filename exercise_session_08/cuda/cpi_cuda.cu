#include <stdio.h>
#include <cuda.h>
extern "C" double getTime(void);

#define NBIN       1000000000  // Number of bins
#define NUM_BLOCK  (2*56)      // default: will be overridden
#define NUM_THREAD (2*8)       // default: will be overridden
#define NITER      1           // default: 1 run (exercise 3 wants this)

// Kernel that executes on the CUDA device
__global__ void cal_pi(double *sum, int nbin, double step,
                       int nthreads, int nblocks)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;  // global thread index
    double local = 0.0;

    // grid-stride loop: verteilt alle NBIN-Iterationen
    for (int i = idx; i < nbin; i += nthreads * nblocks) {
        double x = (i + 0.5) * step;
        local += 4.0 / (1.0 + x * x);
    }

    sum[idx] = local;
}

// Main routine that executes on the host
int main(void)
{
    dim3 dimGrid(NUM_BLOCK, 1, 1);
    dim3 dimBlock(NUM_THREAD, 1, 1);

    double step = 1.0 / (double)NBIN;
    int ntotal  = NUM_BLOCK * NUM_THREAD;
    size_t size = ntotal * sizeof(double);

    double *sumHost = (double *)malloc(size);
    double *sumDev  = NULL;
    cudaMalloc((void **)&sumDev, size);

    for (int j = 0; j < NITER; ++j) {
        cudaMemset(sumDev, 0, size);
        double start = getTime();

        cal_pi<<<dimGrid, dimBlock>>>(sumDev, NBIN, step,
                                      NUM_THREAD, NUM_BLOCK);
        cudaDeviceSynchronize();

        cudaMemcpy(sumHost, sumDev, size, cudaMemcpyDeviceToHost);

        double pi = 0.0;
        for (int t = 0; t < ntotal; ++t)
            pi += sumHost[t];
        pi *= step;

        double delta = getTime() - start;
        printf("PI = %.16g computed in %.4g seconds\n", pi, delta);
    }

    free(sumHost);
    cudaFree(sumDev);
    return 0;
}

