# Exercise sheet 11

## Ex 01

Using perftools with the experiment on nbody (1 MPI rank, 1 thread, runtime 12.7 s, approx 54 MiB memory) shows that 100% of the samples are in main, and about 83% of them come from lines 38–40 in nbody.cpp
, which correspond to the innermost N-body computation loop.

Another 17% of samples are spent inside std::vector (element access) called from that loop. 
Memory traffic is very low (0.05 GB in total), so the code is compute-bound rather than memory-bound. 
This is consistent with the exponential nature of the N-body interaction and tells us that any optimisation (parallelisation with MPI/OpenMP, algorithmic changes, or vectorisation) should focus on this inner loop.


When compiling with the perftools-lite module loaded, the Cray compiler wrappers 
automatically instrument the binary, and the build prints additional messages related 
to CrayPat instrumentation compared to normal compilations in previous sessions.

## Ex 02
Runtime for this execution with using the `sqrt`-function: 

real	0m12.914s
user	0m12.792s
sys	0m0.005s


Runtime for execution using the `sqrtf`-function:

real	0m7.214s
user	0m7.136s
sys	0m0.001s

So the time reduced by not converting the number to double and back

## Ex 03

When we compile the code we get some verbose output telling us about the vectorisation: 

```bash
CC -O3 -march=native -fopt-info-vec -ffast-math -g -o nbody nbody.cpp
nbody.cpp:42:14: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/vector.tcc:515:30: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/vector.tcc:96:27: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors

```

New vectorisation report:

```bash
usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors

```


for me the two reports seems the same? 


With changes the new timing is 

real	0m7.043s
user	0m7.041s
sys	0m0.000s


## Ex 04 

New vectorize report now two 16 byte vectors:

```bash
nbody.cpp:73:31: optimized: loop vectorized using 32 byte vectors
nbody.cpp:73:31: optimized: loop vectorized using 16 byte vectors
nbody.cpp:58:27: optimized: loop vectorized using 32 byte vectors
nbody.cpp:58:27: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
/usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
/usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
```

New timings for code: 

real	0m1.616s
user	0m1.552s
sys	0m0.001s








