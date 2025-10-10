# Exercise Session 03 #
In this session, you will work on modularization of the code and compilation optimization. Moreover, you will parallelize a simple code and successively plot its speedup. 

In this folder you can find:

* cpi.c : the serial version of last week parallel code, needed for Exercise 1
* cpi_mpi.c : the MPI version of cpi code, for Exercise 1
* sum.c : the code needed for Exercise 2 

# Excercise 1

While running the new cpi_mpi we get following ouput:
```bash
Process rank: 0
pi is approximately 3.1415926542566006, Error is 0.0000000006668075
Computed in 4.551 seconds
Computed in 4.554 seconds
``` 

# Excercise 2

led with -O0:

```bash
./sum
sum=10022429073.341873
time = 6.150172 
```

compiled with -D1:
```bash
sum=10022429073.341873
time = 1.189988 
```


compiled with -D2:
```bash
sum=10022429073.341873
time = 1.099336
```

compiled with -D3:
```bash
sum=10022429073.341873
time = 1.117792 
```

other way to get a timing is to run with time like 

```bash
time ./sum 
sum=10022429073.341873
time = 1.099046 

real	0m1.110s
user	0m0.793s
sys	0m0.317s

```
or perf for profiling

```bash
perf stat ./sum
sum=10022429073.341873
time = 1.091377 

 Performance counter stats for './sum':

          1,099.81 msec task-clock:u                     #    0.999 CPUs utilized          
                 0      context-switches:u               #    0.000 /sec                   
                 0      cpu-migrations:u                 #    0.000 /sec                   
             2,643      page-faults:u                    #    2.403 K/sec                  
     2,452,285,565      cycles:u                         #    2.230 GHz                    
            73,035      stalled-cycles-frontend:u        #    0.00% frontend cycles idle   
     1,912,146,964      stalled-cycles-backend:u         #   77.97% backend cycles idle    
     6,711,409,030      instructions:u                   #    2.74  insn per cycle         
                                                  #    0.28  stalled cycles per insn
       536,990,588      branches:u                       #  488.259 M/sec                  
             8,865      branch-misses:u                  #    0.00% of all branches        

       1.101031069 seconds time elapsed

       0.756549000 seconds user
       0.344250000 seconds sys


``` 

- Difference of execution time from -O0 to -O1 is the biggest after this its only mariginal. 
- The optimisation is leaving the debbuging mode and it optimizes the how the memory is used with coping the data in the registers so we have less memory accesses. speeding up the code and removing not needed elements. this goes further and further with higher O loevels
- We can try to paralize some parts of the code

 addeii  I -  



