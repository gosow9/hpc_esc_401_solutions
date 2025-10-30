# Exercise 1 [Ring and deadlocks]

## Q1
It never ends and needs to be shut down since It deadlocks. Everyone blocks in `Ssend` waiting for a matching `Recv`; circular wait forms.

## Q2 

Even ranks send first, odd ranks receive first -> at least one side posts a `Recv`, so no deadlock. Its not optimal, still blocking and adds a global “two‑phase” handshake each step.

## Q3 Why are `Irecv`–`Isend`–`Waitall` (or `Isend`–`Irecv`) better?**  

Non‑blocking avoids circular waits and lets comms progress/overlap with work. One phase, less idle time, scales better.

## Q4 Advantage of a Cartesian communicator
  
Neighbor ranks come “for free” with `MPI_Cart_shift`, periodic BCs are built‑in, and MPI may reorder ranks to match hardware. This is cleaner and usually faster to extend to multi‑D.



