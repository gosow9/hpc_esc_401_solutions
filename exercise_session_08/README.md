# Exercise sheet 08


## Ex 01 

/var/spool/slurmd/job2008863/slurm_script: line 12: cd: /users/crenda/hpc_esc_401_solutions/exercise_8/openacc: No such file or directory
make: Nothing to be done for 'all'.
PI = 3.141592653589793 computed in 1.015 seconds
PI = 3.141592653589793 computed in 0.001153 seconds
PI = 3.141592653589793 computed in 0.00114 seconds
PI = 3.141592653589793 computed in 0.001144 seconds
PI = 3.141592653589793 computed in 0.001139 seconds


No not each Iteration has the same run time, the first one is a lot slower sicne it Needs to do the GPU initialization and JIT, but from Iteration 2 and onwards, the times are very close.



## Ex 02

PI = 3.14159265358979 computed in 0.04857 seconds

No, the times are not the same. In the OpenACC/CPU version the first iteration takes about 1 s, while later iterations are about 0.001 s. The CUDA version takes about 0.049 s for the measured run. The first iteration on both CPU and GPU includes additional one-off overheads such as runtime initialization, context creation, memory allocations and cache warm-up, which make it significantly slower. In addition, CPU/OpenACC and CUDA use different hardware and execution models (threads, vectorization, kernel launches), so they do not have identical per-iteration costs. Finally, OS scheduling and measurement details (what exactly is included in the timed region) introduce further differences between iterations and between implementations.



## Ex 03

See output of slurm file. Not sure what happened but seems like the same result over and over

