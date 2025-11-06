# Exercise sheet 07

## Ex 1



## Ex 2

I added the code into the file `pointer.cpp` the file is compiled with 

```bash 
g++ -O3 -Wall -Wextra  -o pointers pointer.cpp
```

 
a) type(M) = int** (pointer to pointer to int)
b) *M is int* (M[0]); **M is int (M[0][0])
c) M[1][3]=8, *(M[0]+1)=1, *((*(M+1))+3)=8
d) M[0] and M[1] not guaranteed adjacent; *(M[0]+5)==M[1][0] is not guaranteed.
M[0]: 0 1 2 3 4
M[1]: 5 6 7 8 9
M2[0]: 9 8 7 6 5
M2[1]: 4 3 2 1 0

## 
