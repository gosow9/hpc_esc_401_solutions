# Exercise 5 sheet


## Exercise 01


#### `double norm_diff(params p, double** mat1, double** mat2)`

Computes the **root-mean-square difference** between two matrices:
[
\text{norm} = \sqrt{\frac{1}{N_x N_y} \sum_{i,j} (mat1_{ij} - mat2_{ij})^2}
]
Used to measure **convergence** between Jacobi iterations.

---

#### `void jacobi_step(params p, double** u_new, double** u_old, double** f)`

Performs one **Jacobi iteration** for the 2D Poisson equation, updating each interior grid point:
[
u_{i,j}^{new} = \frac{(u_{i+1,j}+u_{i-1,j}),dy^2 + (u_{i,j+1}+u_{i,j-1}),dx^2 - f_{i,j},dx^2,dy^2}{2(dx^2 + dy^2)}
]
Boundary values remain fixed.

---

#### `void init_f(params p, double** f)`

Initializes the **source term** and **boundary conditions** on the grid:

* Interior points: set using `source_term(x, y, rhs_function)`
* Boundary points: set using `boundary(x, y, rhs_function)`


