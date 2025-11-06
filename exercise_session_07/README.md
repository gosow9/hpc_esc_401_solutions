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

## Ex 3


a) y is the row x is the column.
b) 14×6 = 84 elements.
c) Depends on layout: in row-major (C), (1,3) and (1,4) are adjacent; in column-major, (1,3) and (2,3) are.
d) “Better” depends on access pattern: row-major is best for row-wise scans 
e) Row-major: stride in x = 1 (next column is next element).
f) Row-major: stride in y = 14 (skip one whole row).
g) (x=10, y=0) -> index = 0·14 + 10 = 10 -> A[10].
h) (x=0, y=3) -> index = 3·14 + 0 = 42 -> A[42].
i) (x=7, y=4) -> index = 4·14 + 7 = 63 -> A[63].

programm is in index.c compiled and run with
 
```bash
cc -O3 -Wall -o index index.c 
./index >> README.md
```

output of run:
 
(10,0) -> 10
(0,3)  -> 42
(7,4)  -> 63
(0,0)   0  (1,0)   1  (2,0)   2  (3,0)   3  (4,0)   4  (5,0)   5  (6,0)   6  (7,0)   7  (8,0)   8  (9,0)   9  (10,0)  10  (11,0)  11  (12,0)  12  (13,0)  13
(0,1)  14  (1,1)  15  (2,1)  16  (3,1)  17  (4,1)  18  (5,1)  19  (6,1)  20  (7,1)  21  (8,1)  22  (9,1)  23  (10,1)  24  (11,1)  25  (12,1)  26  (13,1)  27
(0,2)  28  (1,2)  29  (2,2)  30  (3,2)  31  (4,2)  32  (5,2)  33  (6,2)  34  (7,2)  35  (8,2)  36  (9,2)  37  (10,2)  38  (11,2)  39  (12,2)  40  (13,2)  41
(0,3)  42  (1,3)  43  (2,3)  44  (3,3)  45  (4,3)  46  (5,3)  47  (6,3)  48  (7,3)  49  (8,3)  50  (9,3)  51  (10,3)  52  (11,3)  53  (12,3)  54  (13,3)  55
(0,4)  56  (1,4)  57  (2,4)  58  (3,4)  59  (4,4)  60  (5,4)  61  (6,4)  62  (7,4)  63  (8,4)  64  (9,4)  65  (10,4)  66  (11,4)  67  (12,4)  68  (13,4)  69
(0,5)  70  (1,5)  71  (2,5)  72  (3,5)  73  (4,5)  74  (5,5)  75  (6,5)  76  (7,5)  77  (8,5)  78  (9,5)  79  (10,5)  80  (11,5)  81  (12,5)  82  (13,5)  83
