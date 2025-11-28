## Ex 04 

for the bonus I have the script block.sh to recompile with different block sizes. Despite having much bigger block sizes with 512 compared to 32 the results we get from running the scripts is small.


Results from running script: 

./block.sh 
Autotuning BLOCKSIZE for N=1000 

=== Testing BLOCKSIZE = 32 === 
Result: PASSED 
GPU time: 0.000199s 
CPU time: 0.004824s 

=== Testing BLOCKSIZE = 64 === 
Result: PASSED 
GPU time: 0.000175s 
CPU time: 0.004834s 

=== Testing BLOCKSIZE = 128 === 
Result: PASSED 
GPU time: 0.000175s 
CPU time: 0.004835s 

=== Testing BLOCKSIZE = 256 === 
Result: PASSED 
GPU time: 0.000178s 
CPU time: 0.004833s 

=== Testing BLOCKSIZE = 512 === 
Result: PASSED 
GPU time: 0.000174s 
CPU time: 0.004824s 

=== Testing BLOCKSIZE = 1024 === 
Result: PASSED 
GPU time: 0.000179s 
CPU time: 0.004826s

speedup from CPU to GPU is around 27x but between different sized I had no real speedup with block sizes?

 
