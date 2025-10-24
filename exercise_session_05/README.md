# Exercise 5 sheet

## Exercise 01


#### `double norm_diff(params p, double** mat1, double** mat2)`

Computes the **root-mean-square difference** between two matrices:


$$\text{norm} = \sqrt{\frac{1}{N_x N_y} \sum_{i,j} (mat1_{ij} - mat2_{ij})^2} $$


Used to measure **convergence** between Jacobi iterations.

---

#### `void jacobi_step(params p, double** u_new, double** u_old, double** f)`

Performs one **Jacobi iteration** for the 2D Poisson equation, updating each interior grid point:


$$u_{i,j}^{new} = \frac{(u_{i+1,j}+u_{i-1,j}),dy^2 + (u_{i,j+1}+u_{i,j-1}),dx^2 - f_{i,j},dx^2,dy^2}{2(dx^2 + dy^2)} $$


Boundary values remain fixed.



---

#### `void init_f(params p, double** f)`

Initializes the **source term** and **boundary conditions** on the grid:

* Interior points: set using `source_term(x, y, rhs_function)`
* Boundary points: set using `boundary(x, y, rhs_function)`


For the commit and results we can find the serial code in the jacobi.cpp file and under the  output folde ra test.png file. 

## Exercise 02

For exercise the code was checked in the repo under the poisson_solver_mp directory. Under the ouput.log file the different runs with up to 16 threads are logged.

To run this first run the 
```bash
make all
```
after compiling the code we can put it into the qeuqe with 

```bash
sbatch run.job
```

Here we run the code with 1,4,8,16 threads. As we see the runtime is nor improving endlessly. I also removed the printf statements to only print the last diff value for comparison. 
The output of the runs is saved in the output.log file for comparison.



## Exercise 03

First we create a Makefile and run.job file so we can compare the runs same as in ex.02 above.

### First task
for the first task I added the code into the file race.c and run it with different amounts of threads. 
This gives us following output:
---

============================
Running with 1 threads
============================
Running with 1 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.05
user 0.04
sys 0.00

============================
Running with 4 threads
============================
Running with 4 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.04
sys 0.00

============================
Running with 8 threads
============================
Running with 8 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.04
sys 0.00

============================
Running with 16 threads
============================
Running with 16 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.02
sys 0.04

---

### Task 2

with the second paralellisation we get 

---

============================
Running with 1 threads
============================
Running with 1 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.05
user 0.04
sys 0.00

============================
Running with 4 threads
============================
Running with 4 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 161430
true number of 0s in file: 646016
real 0.04
user 0.04
sys 0.00

============================
Running with 8 threads
============================
Running with 8 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 80835
true number of 0s in file: 646016
real 0.04
user 0.03
sys 0.00

============================
Running with 16 threads
============================
Running with 16 threads
Size of integer array/file: 1000000
max number in file: 38746
number of 0s in file: 40524
true number of 0s in file: 646016
real 0.05
user 0.05
sys 0.00

---
Here we don't get the same results anymore for all the counts.


### Task 3

I copied the third code into race_1.c here we now have again the correct results if we run with different threads. 

---

============================
Running with 1 threads
============================
Running with 1 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.05
user 0.04
sys 0.00

============================
Running with 4 threads
============================
Running with 4 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.03
sys 0.00

============================
Running with 8 threads
============================
Running with 8 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.03
sys 0.00

============================
Running with 16 threads
============================
Running with 16 threads
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
real 0.04
user 0.02
sys 0.04

---
 The latest run can be found in the output.log file. Also In the latest makefile I used the race_1.c as source and not the race.c. To replicate task2 just change back





