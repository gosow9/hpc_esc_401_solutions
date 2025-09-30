# Exercise Session 02 #
In this session, you will compile and run your first programs on Eiger. This directory contains two versions of the code that were parallelized using MPI or OpenMP.

##Ex_2:


1. First used the cray env. with the command 

```bash
module swap PrgEnv-cray PrgEnv-gnu
```
we can swap the Programming env to a gnu based one.

2. running make command. it compiled the two programms cpi_mpi and cpi_omp. When we execute the compiled programms I get two diffrent results:

```bash 
$ ./cpi_mpi
Process rank: 0
pi is approximately 3.1415926542566006, Error is 0.0000000006668075
Computed in 4.89 seconds
```
for the second command we got following:

```bash 
 ./cpi_omp 
Thread rank: 1
Thread rank: 2
Thread rank: 238
Thread rank: 7
...
Thread rank: 246
pi is approximately 3.1415926542564581, Error is 0.0000000006666649
Computed in 0.08594 seconds
```
Which is way  faster than the first programm.

3. module outputs

```bash
module list

Currently Loaded Modules:
  1) craype-x86-rome                                 8) gcc-native/12.3
  2) libfabric/1.22.0                                9) craype/2.7.30
  3) craype-network-ofi                             10) cray-dsmml/0.2.2
  4) xpmem/2.9.6-1.1_20240510205610__g087dc11fc19d  11) cray-mpich/8.1.28
  5) perftools-base/23.12.0                         12) cray-libsci/23.12.5
  6) cpe/23.12                                      13) PrgEnv-gnu/8.5.0
  7) cray/23.12


```
```bash
module avail

------------ /opt/cray/pe/lmod/modulefiles/mpi/gnu/12.0/ofi/1.0/cray-mpich/8.0 ------------
   cray-hdf5-parallel/1.12.2.9    cray-mpixlate/1.0.3    cray-parallel-netcdf/1.12.3.9

------------------ /opt/cray/pe/lmod/modulefiles/comnet/gnu/12.0/ofi/1.0 ------------------
   cray-mpich-abi/8.1.28    cray-mpich/8.1.28 (L)

----------------------- /opt/cray/pe/lmod/modulefiles/mix_compilers -----------------------
   amd-mixed/6.1.0                     intel-mixed/2023.2.0        (D)
   aocc-mixed/4.1.0                    intel-mixed/2024.0
   cce-mixed/17.0.0                    intel-oneapi-mixed/2023.2.0 (D)
   gcc-native-mixed/12.3               intel-oneapi-mixed/2024.0
   intel-classic-mixed/2023.2.0 (D)    nvhpc-mixed/24.3
   intel-classic-mixed/2024.0          nvidia-mixed/24.3

--------------------- /opt/cray/pe/lmod/modulefiles/compiler/gnu/12.0 ---------------------
   cray-hdf5/1.12.2.9    cray-libsci/23.12.5 (L)

-------------------------- /capstor/apps/cscs/eiger/modulefiles ---------------------------
   CMake/3.20.1                 cpeGNU/23.12                reframe-cscs-tests/24.05
   CMake/3.21.2                 cpeIntel/23.12              reframe-cscs-tests/24.07
   CMake/3.22.1                 ddt/22.1.3-linux-x86_64     reframe-cscs-tests/24.08 (D)
   CMake/3.26.5          (D)    git-lfs/3.4.1               reframe/4.5.1
   EasyBuild-custom/cscs        hub/2.14.2                  reframe/4.6.0            (D)
   NCL/6.6.2                    hwloc/2.4.1                 singularity/3.6.4-eiger
   OOOPS/1.0                    jupyter-utils/0.1           w3m/0.5.3+git20210102-6
   cpeAMD/23.12                 patchelf/0.18.0
   cpeCray/23.12                reframe-cscs-tests/24.03

--------------------- /opt/cray/pe/lmod/modulefiles/perftools/23.12.0 ---------------------
   perftools-lite-events    perftools-lite-hbm      perftools-lite       perftools
   perftools-lite-gpu       perftools-lite-loops    perftools-preload

------------------------ /opt/cray/pe/lmod/modulefiles/net/ofi/1.0 ------------------------
   cray-openshmemx/11.7.0

--------------------- /opt/cray/pe/lmod/modulefiles/cpu/x86-rome/1.0 ----------------------
   cray-fftw/3.3.10.6

--------------------------- /opt/cray/pe/lmod/modulefiles/core ----------------------------
   PrgEnv-aocc/8.5.0         cray-dyninst/12.3.1            intel-oneapi/2023.2.0  (D)
   PrgEnv-cray/8.5.0         cray-libsci_acc/23.12.0        intel-oneapi/2024.0
   PrgEnv-gnu/8.5.0   (L)    cray-mrnet/5.1.2               intel/2023.2.0         (D)
   PrgEnv-intel/8.5.0        cray-pmi/6.1.13                intel/2024.0
   amd/6.1.0          (D)    cray-python/3.11.5             iobuf/2.0.10
   aocc/4.1.0         (D)    cray-stat/4.12.2               nvhpc/24.3             (D)
   atp/3.15.2                craype/2.7.30           (L)    nvidia/24.3            (D)
   cce/17.0.0                craypkg-gen/1.3.31             papi/7.0.1.2
   cpe-cuda/23.12            cudatoolkit/24.3_11.8          perftools-base/23.12.0 (L)
   cpe/23.12          (L)    cudatoolkit/24.3_12.3   (D)    rocm/6.1.0             (D)
   cray-R/4.3.1              gcc-native/12.3         (L)    sanitizers4hpc/1.1.2
   cray-ccdb/5.0.2           gdb4hpc/4.16.0                 valgrind4hpc/2.13.2
   cray-cti/2.18.2           intel-classic/2023.2.0  (D)
   cray-dsmml/0.2.2   (L)    intel-classic/2024.0

------------------ /opt/cray/pe/lmod/modulefiles/craype-targets/default -------------------
   craype-accel-amd-gfx908    craype-hugepages1G      craype-network-ofi (L)
   craype-accel-amd-gfx90a    craype-hugepages256M    craype-network-ucx
   craype-accel-amd-gfx940    craype-hugepages2G      craype-x86-genoa
   craype-accel-host          craype-hugepages2M      craype-x86-milan-x
   craype-accel-nvidia70      craype-hugepages32M     craype-x86-milan
   craype-accel-nvidia80      craype-hugepages4M      craype-x86-rome    (L)
   craype-accel-nvidia90      craype-hugepages512M    craype-x86-spr-hbm
   craype-arm-grace           craype-hugepages64M     craype-x86-spr
   craype-hugepages128M       craype-hugepages8M      craype-x86-trento
   craype-hugepages16M        craype-network-none

---------------------------------- /opt/cray/modulefiles ----------------------------------
   cudatoolkit/24.3_11.8          nvhpc-hpcx/24.3
   cudatoolkit/24.3_12.3          nvhpc-nompi/24.3
   libfabric/1.22.0        (L)    nvhpc-openmpi3/24.3
   nvhpc-byo-compiler/24.3        nvhpc/24.3
   nvhpc-hpcx-cuda11/24.3         rocm/6.1.0
   nvhpc-hpcx-cuda12/24.3         xpmem/2.9.6-1.1_20240510205610__g087dc11fc19d (L)

------------------------------------ /opt/modulefiles -------------------------------------
   amd/6.1.0        intel-classic/2023.2.0    intel-oneapi/2024.0    nvhpc/24.3
   aocc/4.1.0       intel-classic/2024.0      intel/2023.2.0         nvidia/24.3
   darshan/3.2.1    intel-oneapi/2023.2.0     intel/2024.0           rocm/6.1.0

------------------------------------ /etc/cscs-modules ------------------------------------
   cray/23.12 (L)

  Where:
   D:  Default Module
   L:  Module is loaded

If the avail list is too long consider trying:

"module --default avail" or "ml -d av" to just list the default modules.
"module overview" or "ml ov" to display the number of modules for each name.

Use "module spider" to find all possible modules and extensions.
Use "module keyword key1 key2 ..." to search for all possible modules matching any of the
"keys".


``` 

```bash
module spider

---------------------------------------------------------------------------------------
The following is a list of the modules and extensions currently available:
---------------------------------------------------------------------------------------
  Boost: Boost/1.78.0-python3, Boost/1.78.0
    Boost provides free peer-reviewed portable C++ source libraries. 

  CDI: CDI/2.2.4-parallel
    CDI is a C and Fortran Interface to access Climate and NWP model Data. Supported
    data formats are GRIB, netCDF, SERVICE, EXTRA and IEG. 

  CDO: CDO/1.9.10
    CDO is a collection of command line Operators to manipulate and analyse Climate
    and NWP model Data. 

  CMake: CMake/3.20.1, CMake/3.21.2, CMake/3.22.1, CMake/3.26.5
    CMake, the cross-platform, open-source build system. CMake is a family of tools
    designed to build, test and package software. 

  CP2K: CP2K/9.1
...


``` 
lists all possible modules. 

# Ex 3
1. We see the queued jobs. to only show my I can run the `squeue -u $USER` flag
2. file sadded to git
3. add output and error flag to slurm job file 
4.  outputs and erros added to git
5. To format the output we run 
```bash
squeue -o "%.18i %.8u %.10Q %.10a %.15j %.6D %.2t %.20r %.19S %.10L %.10p"
```

# Ex 4
- Running with 1 Thread: Computed in 4.457 seconds
- Running with 10 Threads: Computed in 0.9402 seconds
Once we only have one thread and it takes approx 4.5 seconds in comparison to 10 threads with 1 second.

- Change makefile with O0 flag that is zero optimizasion we have for 10 threads : Computed in 22.99 seconds and with 128 threads: Computed in 23.53 seconds
so no real improvment there




